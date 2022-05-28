#include<iostream>
#include<stdlib.h>

using namespace std;

void square(int row){
    cout<<"Square"<<endl<<endl;
    
    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;
}

void numberAroundNumberSquare(int row){
    int t=0, t2=0, temp=0, temp2=0;
    for(int i=row; i>=1; i--){
        // t = temp;
        // for(int j=1; j<=row; j++){
        //     cout<<i+t<<" ";e
        //     if(t!=0) t--;
        // }
        // temp++;
        //////////////////
        t2 = temp2;
        for(int j=1; j<=row-1; j++){
            cout<<i+t2<<" ";
            if(t2!=0) t2--;
        }
        temp2++;

        cout<<endl;
    }
}

void halfPyramid(int row){
    cout<<"Half Pyramid"<<endl<<endl;
    
    for(int i=0; i<row; i++){
        for(int j=0; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;
}

void inverseHalfPyramid(int row){
    cout<<"Inverse Half Pyramid"<<endl<<endl;

    for(int i=row; i>0; i--){
        for(int j=0; j<i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;
}

void rightPyramid(int row){
    cout<<"Right Pyramid"<<endl<<endl;

    for(int i=1; i<=row; i++){
        for(int j=1; j<=row-i; j++){
            cout<<"  ";
        }
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;
}

void inverseRightPyramid(int row){
    cout<<"Inverse Right Pyramid"<<endl<<endl;

    for(int i=1; i<=row; i++){
        for(int j=0; j<i-1; j++){
            cout<<"  ";
        }
        for(int j=1; j<=row-i+1; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;
}

void fullPyramid(int row){
    cout<<"Full Pyramid"<<endl<<endl;

    for(int i=1; i<=row; i++){
        for(int j=1; j<=row-i; j++){
            cout<<" ";
        }
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;
}

void inverseFullPyramid(int row){
    cout<<"Inverse Full Pyramid"<<endl<<endl;

    for(int i=1; i<=row; i++){
        for(int j=1; j<=i-1; j++){
            cout<<" ";
        }
        for(int j=1; j<=row-i+1; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;
}

void hollowInvertedHalfPyramid(int row){
    cout<<"Hollow Inverted Half Pyramid"<<endl<<endl;

    for(int i=1; i<=row; i++){
        if(i==1 || i==row){
            for(int j=1; j<=row-i+1; j++){
                cout<<"* ";
            }
        }
        else{
            cout<<"* ";
            for(int j=1; j<=row-i-1; j++){
                cout<<"  ";
            }
            cout<<"* ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;
}

void hollowFullPyramid(int row){ 
    cout<<"Hollow Full Pyramid"<<endl<<endl;

    for(int i=1; i<=row; i++){
        for(int j=1; j<=row-i; j++){
            cout<<" ";
        }
        if(i==1 || i==row){
            for(int j=1; j<=i; j++){
                cout<<"* ";
            }
        }
        else{
            cout<<"*";
            for(int j=1; j<=i-1; j++){
                cout<<"  ";
            }
            cout<<"*";
        }
        cout<<endl;
    }

    cout<<endl<<endl;
}

void numberHalfPyramid(int row){
    cout<<"Number Half Pyramid"<<endl<<endl;

    for(int i=1; i<=row; i++){
        for(int j=1; j<=i; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;
}

void numberInvertedHalfPyramid(int row){
    cout<<"Number Inverted Half Pyramid"<<endl<<endl;

    for(int i=row; i>0; i--){
        for(int j=1; j<=i; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;
}

void numberHollowHalfPyramid(int row){
    cout<<"Number Hollow Half Pyramid"<<endl<<endl;

    for(int i=1; i<=row; i++){
        if(i==1 || i==row){
            for(int j=1; j<=i; j++){
                cout<<j<<" ";
            }
        }
        else{
            cout<<1<<" ";
            for(int j=1; j<=i-2; j++){
                cout<<"  ";
            }
            cout<<i<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;
}

void numberFullPyramid(int row){
    cout<<"Number Full Pyramid"<<endl<<endl;

    for(int i=1; i<=row; i++){
        for(int j=1; j<=row-i; j++){
            cout<<"  ";
        }    
        for(int j=0; j<i; j++){
            cout<<i+j<<" ";
        }
        for(int j=i-1; j>=1; j--){
            cout<<i+j-1<<" ";
        }
        
        cout<<endl;
    }

    cout<<endl<<endl;
}

void numberHollowFullPyramid(int row){
    cout<<"Number Hollow Full Pyramid"<<endl<<endl;

    for(int i=1; i<=row; i++){
        for(int j=1; j<=row-i; j++){
            cout<<" ";
        }    
        if(i==1 || i==row){
            for(int j=1; j<=i; j++){
                cout<<j<<" ";
            }
        }
        else{
            cout<<1;
            for(int j=1; j<=i-1; j++){
                cout<<"  ";
            }
            cout<<i;
        }
        cout<<endl;
    }

    cout<<endl<<endl;
}

void numberHollowInvertedHalfPyramid(int row){
    cout<<"Number Hollow Inverted Half Pyramid"<<endl<<endl;

    for(int i=1; i<=row; i++){
        if(i==1 || i==row){
            for(int j=1; j<=row-i+1; j++){
                cout<<i+j-1<<" ";
            }
        }
        else{
            cout<<i<<" ";
            for(int j=1; j<=row-i-1; j++){
                cout<<"  ";
            }
            cout<<row;
        }
        cout<<endl;
    }

    cout<<endl<<endl;
}

void palindromeHalfPyramid(int row){
    cout<<"Palindrome Half Pyramid"<<endl<<endl;

    for(int i=1; i<=row; i++){
        for(int j=1; j<=i; j++){
            cout<<j<<" ";
        }
        for(int j=i-1; j>=1; j--){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;
}

void palindromeABCDHalfPyramid(int row){
    cout<<"Palindrome ABCD Half Pyramid"<<endl<<endl;

    char output;

    for(int i=1; i<=row; i++){
        for(int j=1; j<=i; j++){
            output = 64+j;
            cout<<output<<" ";
        }
        for(int j=i-1; j>=1; j--){
            output = 64+j;
            cout<<output<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;
}

void palindromeFullPyramid(int row){
    cout<<"Palindrome Full Pyramid"<<endl<<endl;

    for(int i=1; i<=row; i++){
        for(int j=1; j<=row-i; j++){
            cout<<"  ";
        }
        for(int j=1; j<=i; j++){
            cout<<j<<" ";
        }
        for(int j=i-1; j>=1; j--){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;
}

void palindromeStarFullPyramid(int row){
    cout<<"Palindrome Star Full Pyramid"<<endl<<endl;

    for(int i=1; i<=row; i++){
        cout<<"****";
        for(int j=1; j<=row-i; j++){
            cout<<"*";
        }
        for(int j=1; j<=i; j++){
            cout<<i<<"*";
        }
        for(int j=1; j<=row-i; j++){
            cout<<"*";
        }
        cout<<"***";
        cout<<endl;
    }

    cout<<endl<<endl;
}

void countingHalfPyramid(int row){
    cout<<"Counting Half Pyramid"<<endl<<endl;
    int t=1;
    for(int i=1; i<=row; i++){
        for(int j=1; j<=i; j++){
            cout<<t++<<" ";
        }
        cout<<endl;
    }     

    cout<<endl<<endl;
}

void pascalTriangle(int row){
    cout<<"Pascal Triangle 1"<<endl<<endl;
    int t=1;
    for(int i=1; i<=row; i++){
        t=1;
        for(int j=1; j<=i; j++){
            cout<<t<<" ";
            t=t*(i-j)/j;
        }
        cout<<endl;
    }     

    cout<<endl<<endl;
}

int factorial(int n){
    int output = 1;
    for(int i=1; i<=n; i++){
        output *= i;
    }
    return output;
}

int nCr(int n, int r){
    return (factorial(n)/(factorial(n-r) * factorial(r)));
}

// 2nd Approch
void pascalTriangle2(int row){
    cout<<"Pascal Triangle 2"<<endl<<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<i; j++){
            cout<<nCr(i, j)<<" ";
        }
        cout<<"1 "<<endl;
    }     

    cout<<endl<<endl;
}

void diamond(int row){
    cout<<"Diamond"<<endl<<endl;

    for(int i=1; i<=row-1; i++){
        for(int j=1; j<=row-i; j++){
            cout<<" ";
        }
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    for(int i=1; i<=row; i++){
        for(int j=1; j<=i-1; j++){
            cout<<" ";
        }
        for(int j=1; j<=row-i+1; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;
}

void hollowDiamond(int row){
    cout<<"Hollow Diamond"<<endl<<endl;

    for(int i=1; i<=row; i++){
        for(int j=1; j<=row-i; j++){
            cout<<" ";
        }
        if(i==1){
            cout<<"* ";
        }
        else{
            cout<<"*";
            for(int j=1; j<=i-1; j++){
                cout<<"  ";
            }
            cout<<"*";
        }
        cout<<endl;
    }   

    for(int i=row-1; i>=1; i--){
        for(int j=1; j<=row-i; j++){
            cout<<" ";
        }
        if(i==1){
            cout<<"* ";
        }
        else{
            cout<<"*";
            for(int j=1; j<=i-1; j++){
                cout<<"  ";
            }
            cout<<"*";
        }
        cout<<endl;
    }   

    cout<<endl<<endl;
}

void solidHalfDiamond(int row){
    cout<<"Solid Half Diamond"<<endl<<endl;

    for(int i=1; i<=row; i++){
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }   
    for(int i=row-1; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }   

    cout<<endl<<endl;
}

void numberSolidHalfDiamond1(int row){
    cout<<"Number Solid Half Diamond 1"<<endl<<endl;

    for(int i=1; i<=row; i++){
        for(int j=1; j<=i; j++){
            cout<<i+2<<" ";
        }
        cout<<endl;
    }   
    for(int i=row-1; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout<<i+2<<" ";
        }
        cout<<endl;
    }   

    cout<<endl<<endl;
}

void numberSolidHalfDiamond2(int row){
    cout<<"Number Solid Half Diamond 2"<<endl<<endl;

    for(int i=1; i<=row; i++){
        for(int j=1; j<=i; j++){
            cout<<i;
            if(j!=i){
                cout<<"*";
            }
        }
        cout<<endl;
    }   
    for(int i=row; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout<<i;
            if(j!=i){
                cout<<"*";
            }
        }
        cout<<endl;
    }   

    cout<<endl<<endl;
}

void numberSolidHalfDiamond3(int row){
    cout<<"Number Solid Half Diamond 3"<<endl<<endl;
    int t = 1;
    for(int i=1; i<=row; i++){
        for(int j=1; j<=i; j++){
            cout<<t++;
            if(j!=i){
                cout<<"*";
            }
        }
        cout<<endl;
    }   
    for(int i=row; i>=1; i--){
        for(int j=0; j<i; j++){
            cout<<t+j-i;
            if(i-j!=1){
                cout<<"*";
            }
        }
        t-=i;
        cout<<endl;
    }   

    cout<<endl<<endl;
}

void numberSolidHalfDiamond4(int row){
    cout<<"Number Solid Half Diamond 3"<<endl<<endl;
    
    cout<<"* "<<endl;
    for(int i=1; i<=row-1; i++){
        cout<<"* ";
        for(int j=1; j<=i; j++){
            cout<<j<<" ";
        }
        for(int j=i-1; j>=1; j--){
            cout<<j<<" ";
        }
        cout<<"* ";
        cout<<endl;
    }     
    for(int i=row-2; i>=1; i--){
        cout<<"* ";
        for(int j=1; j<=i; j++){
            cout<<j<<" ";
        }
        for(int j=i-1; j>=1; j--){
            cout<<j<<" ";
        }
        cout<<"* ";
        cout<<endl;
    }     
    cout<<"* "<<endl;

    cout<<endl<<endl;
}

void blankDiamond(int row){
    cout<<"Blank Diamond"<<endl<<endl;

    for(int i=row; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        for(int j=1; j<=row-i+1; j++){
            cout<<" ";
        }
        for(int j=1; j<=row-i; j++){
            cout<<" ";
        }
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        cout<<endl;
    }         
    for(int i=1; i<=row; i++){
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        for(int j=1; j<=row-i+1; j++){
            cout<<" ";
        }
        for(int j=1; j<=row-i; j++){
            cout<<" ";
        }
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        cout<<endl;
    }         

    cout<<endl<<endl;
}

void halfHalfDiamond(int row){
    cout<<"Half Half Diamond"<<endl<<endl;
    
    for(int i=1; i<=row; i++){
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        for(int j=1; j<=row-i+1; j++){
            cout<<" ";
        }
        for(int j=1; j<=row-i; j++){
            cout<<" ";
        }
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        cout<<endl;
    }         
    for(int i=row; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        for(int j=1; j<=row-i+1; j++){
            cout<<" ";
        }
        for(int j=1; j<=row-i; j++){
            cout<<" ";
        }
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        cout<<endl;
    }         

    cout<<endl<<endl;
}

int main(){
    system("cls");
    
    // square(4);
    numberAroundNumberSquare(3);

    // PYRAMIDS

    // halfPyramid(4);
    // inverseHalfPyramid(4);
    // rightPyramid(4);
    // inverseRightPyramid(4);
    // fullPyramid(6);
    // inverseFullPyramid(6);
    // hollowInvertedHalfPyramid(6);
    // hollowFullPyramid(6);

    // NUMBER PYRAMIDS

    // numberHalfPyramid(5);
    // numberInvertedHalfPyramid(5);
    // numberHollowHalfPyramid(5);
    // numberFullPyramid(5);
    // numberHollowFullPyramid(5);
    // numberHollowInvertedHalfPyramid(5);

    // PALINDROME PYRAMIDS

    // palindromeHalfPyramid(5);
    // palindromeABCDHalfPyramid(5);
    // palindromeFullPyramid(5);
    // palindromeStarFullPyramid(5);
    // countingHalfPyramid(7);
    // pascalTriangle(7);
    // pascalTriangle2(7);

    // DIAMONDS
    
    // diamond(6);
    // hollowDiamond(6);
    // solidHalfDiamond(6);

    // NUMBER DIAMONDS
    
    // numberSolidHalfDiamond1(4);
    // numberSolidHalfDiamond2(4);
    // numberSolidHalfDiamond3(4);
    // numberSolidHalfDiamond4(4);
    // blankDiamond(5);
    // halfHalfDiamond(5);
    

}