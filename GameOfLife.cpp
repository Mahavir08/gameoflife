#include<iostream>
#include<vector>

using namespace std;

class Matrix {
    public:
        int matrixSize, numOfCells;

        void defineMatrixAndCells() {
            // The below two lines are responsible for taking matrix size Ex --> 2x2 Matrix or 3x3 , Please Enter 2 or 3
            cout << "Please enter size of square matrix \n";
            cin >> matrixSize;

            // The below two lines will take number of alive cells a user want to enter.
            cout << "Please enter number of alive cells \n";
            cin >> numOfCells;
        }
};

// Inheritance
class LogicBuiding : public Matrix {
    public:
        void processLogic() {

            vector <vector <int>> arr(matrixSize+2, vector<int>(matrixSize+2,0));
            vector <vector <int>> res(matrixSize+2, vector<int>(matrixSize+2,0));

            // This for loop will take all active cells and feed them to array arr!
            for (int i = 0; i < numOfCells; i++)
                {
                    cout << "Please enter row and column of alive cell separated by space\n";
                    int a, b;
                    cin >> a >> b;
                    arr[a+1][b+1] = 1;
                }

            // This below loop will be applying logic based on the below mentioned points -> 

            // 1. Any live cell with fewer than two live neighbours dies, as if by loneliness.
            // 2. Any live cell with more than three live neighbours dies, as if by overcrowding.
            // 3. Any live cell with two or three live neighbours lives, unchanged, to the next generation.
            // 4. Any dead cell with exactly three live neighbours comes to life.


            for (int i = 1; i < matrixSize+1; i++)
                {
                    for (int j = 1; j < matrixSize+1; j++)
                    {   
                        int count = arr[i+1][j] + arr[i-1][j] + arr[i+1][j+1] + arr[i-1][j+1] + arr[i][j+1] + arr[i][j-1] + arr[i+1][j-1] + arr[i-1][j-1]; 
                        if(count<2) res[i][j] = 0;  //Died because of loneliness
                        if(count>3) res[i][j] = 0;  //Died because overcrowding
                        if(arr[i][j]==1 && (count==2 || count==3)) res[i][j] = 1; //Unchanged
                        if(arr[i][j]==0 && count==3) res[i][j] = 1; //Alive because of 3 Live neighbours
                    }
                }

            cout << "Output is\n";

            // Output generating Loop !!

            for (int i = 1; i < matrixSize+1; i++)
            {
                for (int j = 1; j < matrixSize+1; j++)
                {   
                    if(res[i][j]==1) cout<<i-1<<" "<<j-1<<endl;
                }
            }
        }
};

int main() {
    LogicBuiding obj;
    obj.defineMatrixAndCells();
    obj.processLogic();
    return 0;
}