//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███                                                  //
//            █ █        █ █        GameCore.h                                //
//             ████████████         Mastermind Core                           //
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
//MastermindCore.
#include "MastermindCore_Utils.h"
#include "MastermindCore_Types.h"

NS_MASTERMINDCORE_BEGIN

class GameCore
{
    // Constants //
public:
    ///@brief Player has no restriction in how many moves can be
    ///perfomed util the right sequence is found.
    ///@see GameCore::GameCore().
    static const int kUnlimitedMoves;

    static const int kRandomSeed;

    // CTOR/DTOR //
public:
    GameCore(int sequenceSize, int colorsCount, 
             int maxMoves,     int seed = kRandomSeed);

    // Public Methods //
public:
    GuessStatus checkGuess(const Sequence &sequence);

    const Sequence& getSequence() const;
    
    int getValueAt(int index) const;
    
    Status getStatus() const;

    int getMovesCount() const;
    int getMaxMovesCount() const;
    
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

NS_MASTERMINDCORE_END
#endif // defined(__MastermindCore_include_GameCore_h__) //
