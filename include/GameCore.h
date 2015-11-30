//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███                                                  //
//            █ █        █ █        GameCore.h                                //
//             ████████████         CoreMastermind                            //
//           █              █       Copyright (c) 2015 AmazingCow             //
//          █     █    █     █      www.AmazingCow.com                        //
//          █     █    █     █                                                //
//           █              █       N2OMatt - n2omatt@amazingcow.com          //
//             ████████████         www.amazingcow.com/n2omatt                //
//                                                                            //
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
//        The email is: acknowledgmentopensource@AmazingCow.com               //
//     3. Altered source versions must be plainly marked as such,             //
//        and must notbe misrepresented as being the original software.       //
//     4. This notice may not be removed or altered from any source           //
//        distribution.                                                       //
//     5. Most important, you must have fun. ;)                               //
//                                                                            //
//      Visit opensource.amazingcow.com for more open-source projects.        //
//                                                                            //
//                                  Enjoy :)                                  //
//----------------------------------------------------------------------------//

#ifndef __MastermindCore_include_GameCore_h__
#define __MastermindCore_include_GameCore_h__

//std
#include <string>
//CoreMastermind
#include "CoreMastermind_Utils.h"
#include "CoreMastermind_Types.h"

NS_COREMASTERMIND_BEGIN

class GameCore
{
    // Constants //
public:
    ///@brief Player has no restriction in how many moves can be
    ///performed until the right sequence is found.
    ///@see GameCore::GameCore().
    static const int kUnlimitedMoves;

    ///@brief Meta value meaning that a Random seed should be used.
    ///@see GameCore::GameCore()
    static const int kRandomSeed;

    // CTOR/DTOR //
public:
    ///@brief Constructs the MasterMind GameCore.
    ///@warning No sanity checks are made to ensure the
    ///arguments validity.
    ///@param sequenceSize The length of sequence - Must be > 0.
    ///@param colorsCount How many colors can be used - Must be >= sequenceSize.
    ///@param maxMoves How many tries player has.
    ///@param seed The seed or GameCore::kRandomSeed.
    GameCore(int sequenceSize, int colorsCount,
             int maxMoves,     int seed = kRandomSeed);

    // Public Methods //
public:
    ///@brief Check if the player's guess is right.
    ///@param sequence A valid sequence.
    ///@returns A guess status object with the info about the guess.
    ///@see Sequence, GuessStatus.
    GuessStatus checkGuess(const Sequence &sequence);


    ///@brief Get the target sequence.
    ///@returns The target sequence.
    ///@see GameCore::checkGuess, Sequence.
    const Sequence& getSequence() const;


    ///@brief Get the value of sequence at index.
    ///@param index The index of queried value.
    ///@warning index must be on Sequence bounds.
    ///@see Sequence.
    int getValueAt(int index) const;


    ///@brief Get the current Game status.
    ///@returns The current Game Status.
    ///@see Status.
    Status getStatus() const;


    ///@brief Gets how many moves player did so far.
    ///@returns The count of player's moves.
    ///@see Status, GameCore::kUnlimitedMoves, GameCore::getMaxMovesCount.
    int getMovesCount() const;

    ///@brief Gets how many moves player can do
    ///@returns The max amount of moves or GameCore::kUnlimitedMoves.
    ///@see Status, GameCore::kUnlimitedMoves, GameCore::getMaxMovesCount.
    int getMaxMovesCount() const;


    ///@brief Gets the actual seed used to generate the game.
    ///@see GameCore::kRandomSeed.
    int getSeed() const;

    // Private Methods //
private:
    void initializeSequence();

    // iVars //
private:
    Sequence m_sequence;

    int m_sequenceSize;
    int m_colorsCount;

    Status m_status;

    int m_movesCount;
    int m_maxMovesCount;

    int m_seed;
};

NS_COREMASTERMIND_END
#endif // defined(__MastermindCore_include_GameCore_h__) //
