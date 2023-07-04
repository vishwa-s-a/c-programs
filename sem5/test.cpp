// code for checksum calculation and verification

#include<bits/stdc++.h>

using namespace std;

//function to calculate the one's complement of the given binary string
string onesComplemen(string data)
{
    for(int i=0;i<data.length();i++)
    {
        if(data[i]=='0')
        data[i]='1';

        else
        data[i]='0';
    }
    return data;
}

//function to return the checksum of the given string when divided into blocks of size of k bits
string checkSum(string data, int blockSize)
{
    // here the blockSize refers to the size of bits that should be taken once from the given string of data
    int n=data.length();
    if(n%blockSize!=0)
    {
        // now we will add some extra zeros so we get the perfect number of blocks of size of k bits
        int padding=blockSize-(n%blockSize);// here padding refers to number of zeroes that should be added from the starting part of string

        for(int i=0;i<padding;i++)
        {
            data='0'+data;
        }
    }

    //now we do binary addition of all blocks with carry
    string result="";// to store the final addition result

    //at first we will added the first k bits directly to empty string result
    for(int i=0;i<blockSize;i++)
    {
        result+=data[i];
    }

    //loop to calculate the the block wise addition of data
    for(int i=blockSize;i<n;i+=blockSize)
    {
        // using the above for loop we will select a block of k bits everytime

        string nextBlock="";
        // in this following loop we will copy next block of k bits from data string
        for(int j=i;j<i+blockSize;j++)
        {
            nextBlock+=data[j];
        }

        //variable to store the addition of 2 blocks
        string addition="";
        int sum=0,carry=0;

        //loop to calculate the binary addition of the current 2 blocks of k size
        for(int k=blockSize-1;k>=0;k--)
        {
            sum+=(result[k]-'0')+(nextBlock[k]-'0');
            carry=sum/2;//if it is 0 then no carry. or else carry is there

            if(sum==0)// this is when we get 0+0
            {
                addition='0'+addition;
            }
            else if(sum==1)//this when we get 0+1
            {
                addition='1'+addition;
            }
            else if(sum==2)//this is when we get 1+1
            {
                addition='0'+addition;
            }
            else{// this is when we get 1+1+1
                addition='1'+addition;
            }
            sum=carry;

        }
        
        string final="";

        //after binary addition of two blocks with carry, if carry is 1 then apply binary addition
        // wrapping of numbers to get k bits again, which is the size of the block
        if(carry==1)
        {
            for(int q=addition.length()-1;q>=0;q--)
            {
                if(carry==0){
                    final=addition[q]+final;
                }
                else if(((addition[q]-'0')+carry)%2==0)
                {
                    //this is when 1+1 comes 
                    final="0"+final;
                    carry=1;
                }
                else{
                    final="1"+final;
                    carry=0;
                }
            }

            result=final;
        }
        else{
            result=addition;
        }
    }

    return onesComplemen(result);
}

//function to check if the received message is same as the senders message using checksum
bool checker(string sentMessage, string receivedMessage, int blockSize)
{
    string senderChecksum=checkSum(sentMessage,blockSize);

    string receiverChecksum=checkSum(receivedMessage+senderChecksum,blockSize);

    // to check whether we got all zeroes in final checksum or not we use
    //count function which count the occurence of a particular character in the string between the specified indices
    // count '0' from start to end of string
    if(count(receiverChecksum.begin(),receiverChecksum.end(),'0')==blockSize)
    {
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    printf("Name:Vishwa S Appaji\tRegNo:21BCI0026\n");
    string sent_message= "10000101011000111001010011101101";
    int block_size=8;
    cout<<"Sent message is :"<<sent_message<<endl;
    string recv_message= "10000101011000111001010011101101";
    cout<<"Received message is :"<<recv_message<<endl;
    cout<<"Check sum of the sent message is: ";
    cout<<checkSum(sent_message,block_size)<<endl;

    if(checker(sent_message,recv_message,block_size))
    cout<<"No Error found"<<endl;

    else
    cout<<"Error found"<<endl;

    return 0;
}

