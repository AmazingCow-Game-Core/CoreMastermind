//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        GameCore.cpp                              //
//            █ █        █ █        CoreMastermind                            //
//             ████████████                                                   //
//           █              █       Copyright (c) 2015, 2016                  //
//          █     █    █     █      AmazingCow - www.AmazingCow.com           //
//          █     █    █     █                                                //
//           █              █       N2OMatt - n2omatt@amazingcow.com          //
//             ████████████         www.amazingcow.com/n2omatt                //
//                                                                            //
//                  This software is licensed as GPLv3                        //
//                 CHECK THE COPYING FILE TO MORE DETAILS                     //
//                                                                            //
//    Permission is granted to anyone to use this software for any purpose,   //
//   including commercial applications, and to alter it and redistribute it   //
//               freely, subject to the following restrictions:               //
//                                                                            //
//     0. You **CANNOT** change the type of the license.                      //
//     1. The origin of this software must not be misrepresented;             //
//        you must not claim that you wrote the original software.            //
//     2. If you use this software in a product, an acknowledgment in the     //
//        product IS HIGHLY APPRECIATED, both in source and binary forms.     //
//        (See opensource.AmazingCow.com/acknowledgment.html for details).    //
//        If you will not acknowledge, just send us a email. We'll be         //
//        *VERY* happy to see our work being used by other people. :)         //
//        The email is: acknowledgment_opensource@AmazingCow.com              //
//     3. Altered source versions must be plainly marked as such,             //
//        and must not be misrepresented as being the original software.      //
//     4. This notice may not be removed or altered from any source           //
//        distribution.                                                       //
//     5. Most important, you must have fun. ;)                               //
//                                                                            //
//      Visit opensource.amazingcow.com for more open-source projects.        //
//                                                                            //
//                                  Enjoy :)                                  //
//----------------------------------------------------------------------------//

//Header
#include "../include/GameCore.h"

//std
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <ctime>

//Usings.
USING_NS_COREMASTERMIND;

// Constants //
const int GameCore::kUnlimitedMoves = -1;
const int GameCore::kRandomSeed     = -1;

// CTOR/DTOR //
GameCore::GameCore(int sequenceSize, int colorsCount,
                   int maxMoves,     int seed /* = kRandomSeed */ ) :
    // m_sequence - Initialized in initializeSequence.
    m_sequenceSize (sequenceSize),
    m_colorsCount  (colorsCount),
    m_status       (Status::Continue),
    m_movesCount   (0),
    m_maxMovesCount(maxMoves),
    m_seed         (seed) //Could change in initializeSequence.
{
    initializeSequence();
}


// Public Methods //
GuessStatus GameCore::checkGuess(const Sequence &guessSequence)
{
    //Game is over - Return an invalid Guess Status.
    if(m_status != Status::Continue)
    {
        GuessStatus::Invalid();
    }

    GuessStatus status;

    //Iterate for the sequences finding the matches of
    //colors and colors and places.
    for(int i = 0; i < static_cast<int>(m_sequence.size()); ++i)
    {
        int color = guessSequence[i];
        if(color == m_sequence[i])
        {
            ++status.rightColorsAndPlaces;
        }
        else
        {
            auto it = std::find(begin(m_sequence), end(m_sequence), color);
            if(it != end(m_sequence))
                ++status.rightColors;
        }
    }

    //Move was perfomed.
    ++m_movesCount;

    //Check the status:
    //  First check if player hit the whole sequence
    //  if not, check if the moves was over.
    //Either case is a game over situation.
    if(status.rightColorsAndPlaces == static_cast<int>(m_sequence.size()))
    {
        m_status = Status::Victory;
    }
    else if(m_movesCount >= m_maxMovesCount &&
            m_maxMovesCount != GameCore::kUnlimitedMoves) //Has moves constraint.
    {
        m_status = Status::Defeat;
    }

    return status;
}

const Sequence& GameCore::getSequence() const
{
    return m_sequence;
}

int GameCore::getValueAt(int index) const
{
    return m_sequence.at(index);
}

Status GameCore::getStatus() const
{
    return m_status;
}

int GameCore::getMovesCount() const
{
    return m_movesCount;
}
int GameCore::getMaxMovesCount() const
{
    return m_maxMovesCount;
}

int GameCore::getSeed() const
{
    return m_seed;
}

// Private Methods //
void GameCore::initializeSequence()
{
    //COWTODO: Start using the CoreRandom.
    //Initialize the random number generator.
    if(m_seed == GameCore::kRandomSeed)
        m_seed = static_cast<int>(time(nullptr));


    //Create a list of possible colors.
    std::vector<int> colorsList(m_colorsCount);
    std::iota(begin(colorsList), end(colorsList), 0);

    std::shuffle(begin(colorsList),
                 end(colorsList),
                 std::default_random_engine(m_seed));


    //Initialize the sequence.
    //Fill the sequence with random colors from previous list.
    m_sequence.reserve(m_sequenceSize);
    while(static_cast<int>(m_sequence.size()) != m_sequenceSize)
    {
        int color = colorsList.back();
        colorsList.pop_back();

        m_sequence.push_back(color);
    }
}
