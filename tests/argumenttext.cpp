#include <iostream>
using namespace std;

// When passing char arrays as parameters they must be pointers
int main(int argc, char* argv[]) {
    //if (argc < 5) { // Check the value of argc. If not enough parameters have been passed, inform user and exit.
    //    std::cout << "Usage is -in <infile> -out <outdir>\n"; // Inform the user of how to use the program
    //    std::cin.get();
    //    exit(0);
	//		}
     if (argc < 1) { // if we got enough parameters...
        string action, key, algorithm, text;
        std::cout << argv[0];
        for (int i = 1; i < argc; i++) { /* We will iterate over argv[] to get the parameters stored inside.
                                          * Note that we're starting on 1 because we don't need to know the 
                                          * path of the program, which is stored in argv[0] */
            if (i + 1 != argc) // Check that we haven't finished parsing already
                if (argv[i] == "-a") {
                    // We know the next argument *should* be the filename:
                    action = argv[i + 1];
                } else if (argv[i] == "-k") {
                    key = argv[i + 1];
                } else if (argv[i] == "-g") {
                    algorithm = argv[i + 1];
				} else if (argv[i] == "-t"){
					text = argv[i + 1];
                } else {
                    std::cout << "Not enough or invalid arguments, please try again.\n";
                    //Sleep(2000); 
                    exit(0);
            }
            std::cout << argv[i] << " ";
        }
        //... some more code
        std::cin.get();
        return 0;
    }
}