#include <bits/stdc++.h>

/*
    1. create global matrix of 8x8
    2. make function to print matrix
    3. take input column number
    4. check if new 4connect formed
    5. print new matrix
    6. go to 3

*/
using namespace std;

int matrix[8][8];

void initMatrix()
{
    for(int row=0;row<8;row++){
        for(int col=0;col<8;col++){
            matrix[row][col]=0;
        }
    }
}

void printMatrix()
{
    for(int row=0; row<8; row++)
    {
        cout<<"| ";
        for (int col=0;col<8;col++)
        {
            cout<<matrix[row][col]<<" | ";
        }
        cout<<endl;
    }
}

int northEast(int playerNumber, int row, int col)
{
    int count=0;
    for(int step =1; step<=3; step++)
    {
        // matrix[row-step][col+step]
        if(row-step <0 || col+step>7) break;
        if(matrix[row-step][col+step] != playerNumber) break;
        count++;
    }
    return count;
}

int northWest(int playerNumber, int row, int col)
{
    int count=0;
    for(int step =1; step<=3; step++)
    {

        if(row-step <0 || col-step<0) break;
        if(matrix[row-step][col-step] != playerNumber) break;
        count++;
    }
    return count;
}

int southEast(int playerNumber, int row, int col)
{
    int count=0;
    for(int step =1; step<=3; step++)
    {

        if(row+step>7 || col+step>7) break;
        if(matrix[row+step][col+step] != playerNumber) break;
        count++;
    }
    return count;
}

int southWest(int playerNumber, int row, int col)
{
    int count=0;
    for(int step =1; step<=3; step++)
    {

        if(row+step >7 || col-step<0) break;
        if(matrix[row+step][col-step] != playerNumber) break;
        count++;
    }
    return count;
}




int east(int playerNumber, int row, int col)
{
    int count=0;
    for(int step=1;step<=3;step++)
    {
        if(col + step >7)break;
        if(matrix[row][col+step] != playerNumber)break;
        count++;
    }
    return count;
}

int west(int playerNumber, int row, int col)
{
    int count=0;
    for(int step=1;step<=3;step++)
    {
        if(col - step <0)break;
        if(matrix[row][col-step] != playerNumber)break;
        count++;
    }
    return count;
}
int south(int playerNumber, int row, int col)
{
    int count=0;
    for(int step=1;step<=3;step++)
    {
        if(row + step >7)break;
        if(matrix[row+step][col] != playerNumber)break;
        count++;
    }
    return count;
}



bool checkChoice(int choice)
{
    //if(choice<1 || choice>8) return false;
    if(choice>=1 && choice<=8)
    {
        if(matrix[0][choice-1] == 0)
        {
            return true;
        }
        cout<<"Column "<<choice<<" is full\n";
        return false;
    }
    cout<<"Choice should be between 1 and 8\n";
    return false;
}

bool checkWin(int playerNumber, int row, int col)
{
    int ne = northEast(playerNumber, row, col);
    int e = east(playerNumber, row, col);
    int se = southEast(playerNumber, row, col);
    int s = south(playerNumber, row, col);
    int sw = southWest(playerNumber, row, col);
    int w = west(playerNumber, row, col);
    int nw = northWest(playerNumber, row, col);
    if(ne + sw + 1 >=4) return true;
    if(e + w + 1>=4) return true;
    if(se + nw + 1 >=4) return true;
    if (s+1>=4) return true;

    return false;

}

int main()
{
    initMatrix();
    printMatrix();
    int choice=-1; //choice can be 1 to 8
    int counter=0; //counts the number of turns
    bool gameOver = false;
    int playerNumber =1; //turn of which player
    int rowNum=1;

    while(!gameOver && counter<64)
    {
        cout<<"Player "<<playerNumber<<"'s turn\n";
        cout<<"Enter column number\n";
        cin>>choice;
        // check i choice is between 1 and 8 and if column is not full
        while(!checkChoice(choice))
        {
            cout<<"Enter choice again\n";
            cin>>choice;
        }
        //change matrix according to choice

        for(int row = 7; row>=0; row--)
        {
            if(matrix[row][choice-1] == 0)
            {
                matrix[row][choice-1] = playerNumber;
                rowNum = row;
                break;
            }
        }


        //check if gameOver
        if(checkWin(playerNumber, rowNum, choice-1))
        {
            gameOver = true;
            cout<<"Player "<<playerNumber<<" wins!\n";
        }
        printMatrix();
        counter++;
        playerNumber = 3 - playerNumber;

    }
    return 0;
}

