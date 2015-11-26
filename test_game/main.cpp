//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███                                                  //
//            █ █        █ █        main.cpp                                  //
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


//This guard is to ease the usage of the MastermindCore,
//so it's users won't need to worry about removing any files
//since is very unlikely that this flag is defined elsewhere.
#ifdef __AMAZINGCORE_MASTERMINDCORE_TEST_ENABLED__

#include <iostream>
#include <vector>
#include <cstdlib>
#include "../include/MastermindCore.h"

USING_NS_MASTERMINDCORE;
using namespace std;

void usage()
{
    cout << "Amazing Cow - MastermindCore Test Game" << endl;
    cout << "Usage:" << endl;
    cout << "  <binary-name> sequenceSize colorsCount maxMoves showSequence" << endl;
    cout << "Ex: ./testgame 4 8 10 1 //1 Show sequence" << endl;
    cout << "Ex: ./testgame 4 8 10 0 //0 DONT Show sequence" << endl;

    exit(1);
}

int main(int argc, const char *argv[])
{
    if(argc != 5)
        usage();

    auto sequenceSize = atoi(argv[1]);
    auto colorsCount  = atoi(argv[2]);
    auto maxMoves     = atoi(argv[3]);
    auto showSequence = atoi(argv[4]);

    GameCore core(sequenceSize, colorsCount, maxMoves);

    while(core.getStatus() == Status::Continue)
    {
        //Print the "sequence".
        for(int i = 0; i < core.getSequence().size(); ++i)
        {
            if(showSequence)
                cout << core.getValueAt(i) << " ";
            else
                cout <<  "x ";
        }

        //Print the status...
        cout << "Move ( "
             << core.getMovesCount()
             << ") of ( "
             << core.getMaxMovesCount()
             << ")" << endl;

        cout << "Enter sequence..." << endl;
        vector<int> guess;
        while(guess.size() != core.getSequence().size())
        {
            int a;
            cin >> a;
            guess.push_back(a);
        }

        auto guessStatus = core.checkGuess(guess);

        cout << "Guess status             " << endl
             << "Right Colors           : " << guessStatus.rightColors          << endl
             << "Right Colors and Places: " << guessStatus.rightColorsAndPlaces << endl
             << endl;
    }

}

#endif // __AMAZINGCORE_MASTERMINDCORE_TEST_ENABLED__ //
