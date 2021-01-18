/* Matthew Kale, 5005997901, CS 135 - 1007, Assignment 6
 * Description: Program that reads in a file and creates either an up arrow,
 *              side arrow, or zero. and reads in a file, preforms simple 
                calculations, and writes the data to an output file.
 * Input: Input file name
 * Output: text file for each shape with the shape created inside
*/

/* Algorithm:
1) Create program shell
2) Declare variables
3) Open file
4) Loop in reading values
5) Create output file name
6) Test type of shape
7) Write out shape
    a) Right arrow (Do While loop)
        - Declare variables
        - Write out spaces before
        - Write out Characters increasing in amount each line
        - Write out shaft
        - Write out Spaces
        - Write out Characters in decreasing amount each line
    b) Up arrow (While loop)
        - Declare variables
        - Write out spaces decreasing each line
        - Write out characters increasing each line
        - Write out shaft
        - Write out characters increasing each line
    c) Zero (for loop)
        - Declare variables
        - Write out top line
        - Write out first character then spaces before (decreasing)
        - Write out character then spaces after (increasing)
        - Write out final coloumn
        - Write out bottom line
8) Loop back to the beginning to check if the file is at the end
9) When the file ends, Close the input 
*/






#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{
    ifstream inFile;
    string type;
    int size = 0;
    char letter;
    string fileName;
    int list = 0;
    int num = 0;    
    ofstream oFile;


    // Open File
    cout << "Enter input file name: ";
    cin >> fileName;
    inFile.open ( fileName );
    
    while (inFile.eof()== false){
    // Read in 
    inFile >> type >> size >> letter;
    if (inFile.eof() == true){return 0;}
    cout << "Shape Created: " << type << "_" << size << ".txt" << endl;

    oFile.open ( type + "_" + to_string(size) + ".txt");
    

    // RIGHT ARROW    
    // Test type and write out information
    if (type == "rightArrow"){
        oFile << "Symbol: Right Arrow  Size: " << size << " Character: '" << letter << "'" << endl; 

        // Ensure size is even
        if (size % 2 != 0){
            size = size + 1;
            oFile << "Note: Right Arrow must have an even size.  Shape created with size: " << size;
        }
    
        oFile << endl;

        // Write out guide line
        do{        
            
            num++;
            if(num >= 10){
                num -=10;
            }
            else if(num >= 20){
                num -=20;
            }
            list++;
            oFile << num;
        }while(list < size);

        oFile << endl << endl;

        // Declare variables
        int spacesB = (size/2);
        int a = 0;
        int b = 0;
        int d = 1;
        int numB = ((size/size)-1);
        int e = 1;
        int f = 1;
        
        // Top Triangle
        do{
            if(b == ((size/2)-1)){break;}
            b++;

            // Spaces
            int i = 0;      
            do{
            oFile << ' ';
            
            i++;
            
            }while(i < (spacesB) );   

            int a = 1;
            
            // Characters
            do{
                do{
                    oFile << letter;
                    a++;
                }while(a <= d);
               
                d++;
                
            }while(a < (numB));
        
            oFile << endl;
            a++;
        }while(a <= size);

        // Middle Lines     
        do{
                oFile << letter;
                e++;
        }while(e <= size);  

        oFile << endl;

        do{
            oFile << letter;
            f++;
        }while(f <= size);  

        oFile << endl;

        // Reinitialize Variables
        a = 0;
        b = 0;
        d = 3; 
        numB = ((size/size)-1);
      
        // Bottom triangle
        do{
            if(b == ((size/2)-1)){break;}
            b++;

            // Spaces
            int i = 0;      
            do{
            oFile << ' ';
            
            i++;
            
            }while(i < (spacesB) );   

            int a = 1;
            
            // Characters
            do{
                do{
                    oFile << letter;
                    a++;
                }while(a <= d);
               
                d--;
                
            }while(a < (numB));
        
            oFile << endl;
            a++;
        }while(a <= size);
    }


    // UP ARROW
    // Test type and write out information
    if (type == "upArrow"){
        oFile << "Symbol: Up Arrow  Size  " << size << " Character: '" << letter << "'" << endl; 

        if (size % 2 != 0){
            size = size + 1;
            oFile << "Note: Up Arrow must have an even size.  Shape created with size: " << size;
        }
        oFile << endl;

        // Ensure number is even
        while(list < size){        
            num++;
            if(num >= 10){
                num -=10;
            }
            else if(num >= 20){
                num -=20;
            }
            list++;
            oFile << num;
        }

        oFile << endl << endl;

        // Declare Variables    
        int i = 0;
        int spacesB = ((size/2)-1);
        int tNum = 2;
        int letters = 0;
        int h = 0;
        int sp2 = 0;

        // Write out Triangle
        while(i < (((size/2)-1))){
            
            int a =0;

            // Write out spaces
            while (a < spacesB){
                oFile << ' ';
                a++;

            }
        
            int b = 0;
            // Write out Characters
            while ( b < tNum){
                oFile << letter;
                b++;
            }
                
            oFile << endl;
            i++;
            spacesB--;
            tNum += 2;
        }

        // Write out base
        while (letters < size){
            oFile << letter;
            letters++;
        }
        oFile << endl;

        // Write out sharft
        while ( h < (size/2)){
            sp2 = 0;
            while (sp2 < ((size/2)-1)){
                oFile << ' ';
                sp2++;
            }
            oFile << letter << letter << endl;
            h++;
        }
        oFile << endl;
    }


    // ZERO
    // Test type and write out information
    if (type == "zero"){
        oFile << "Symbol: ZERO  Size  " << size << " Character: '" << letter << "'" << endl; 
    
        // Ensure number is even
        if (size % 2 != 0){
            size = size + 1;
            oFile << "Note: Zero must have an even size.  Shape created with size: " << size;
        }
        
        oFile << endl;

        // Write out guide line
        for(int i=0; i < size; i++){        
            num++;
            if(num >= 10){
                num -=10;
            }
        else if(num >= 20){
            num -=20;
        }
        list++;
        oFile << num;
        }

        oFile << endl << endl;

        // Decalre variables
        int spacesB = (size-3);
        int spacesA = 0;

        // Top line
        for (int i = 0; i <= (size-1); i++){
            oFile << letter;
        }
        oFile << endl;
        
        // left most vertical line
        for (int i = 0; i < (size-2); i++){
            oFile << letter;
            // Inside Spaces (left)    
            for (int i = 0; i < spacesB; i++){
                oFile << " ";
            }
            // Diagonal        
            for (int bLine = 2; bLine > 1; bLine--){
                oFile << letter;
            }
            // inside spaces (right)    
            for (int i = 1; i <= spacesA; i++){
                oFile << " " ;
                if(spacesA == (size - 2)){
                    break;
                }
            }

            spacesB--;
            spacesA++;
            // right most vertical line
            oFile << letter;
            oFile << endl;      
                
        }
        // Bottom line
        for (int i = 0; i <= (size-1); i++){
            oFile << letter;
        }
        
        oFile << endl << endl << endl;
    }

    oFile.close();
    }
    inFile.close();
}
