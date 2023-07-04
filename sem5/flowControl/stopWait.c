#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX 8
int sender[MAX];
int receiver[MAX];
int sn = 0;
int rn = 0;

// Simulating the frame transmission
bool sendFrame(int frameNumber) {
    printf("sn: %d  rn: %d\n",sn,rn);
    printf("Sending Frame %d\n", frameNumber);
    usleep(2000); // Simulating transmission delay

    return true;
}

// Simulating the ACK reception
bool receiveACK(int frameNumber,int  state) {
    if(state==1)//received the frame and ack sent
    {
        rn++;
        sn++;
        printf("Received Frame %d\n", frameNumber);
        printf("Ack for frame: %d\n",rn);
        usleep(2000); // Simulating reception delay
        printf("sn: %d  rn: %d\n",sn,rn);
        return true;

    }
    else if(state==2)//frame is lost
    {
        printf("Frame lost : %d\n",frameNumber);
        printf("time out\n");
        printf("sn: %d  rn: %d\n",sn,rn);
        return false;

    }
    else{// ack is lost
        rn++;
        printf("Received Frame %d\n", frameNumber);
        printf("Ack for frame lost: %d\n",rn);
        printf("sn: %d  rn: %d\n",sn,rn);
        return false;
    }
}
void resend(int frameNumber,int state)
{
        printf("|=======Resending frame: %d=======|",frameNumber);
        printf("\n************sender*******************\n");
        bool temp1=sendFrame(sn);
        if(state==3)
        rn--; 
        printf("\n************receiver****************\n");
        bool temp2=receiveACK(sn,1); 
          
}

int main() {
    for(int i=0;i<MAX;i++)
    {
        sender[i]=i;
        receiver[i]=i;
    }
    int frameNumber = 1;
    int framesSent = 0;

    //first 5 frames are sent and ack is also received without any problem
    for(int i=0;i<5;i++)
    {
        printf("\n************sender******************\n");
        bool temp1=sendFrame(sn);
        printf("\n************receiver****************\n");
        bool temp2=receiveACK(sn,1);
        
    }
    //frame is lost
    printf("\n************sender*********************\n");
    sendFrame(sn);
    printf("\n************receiver*******************\n");
    receiveACK(sn,2);
    resend(sn,2);
    //ack lost
    printf("\n************sender*********************\n");
    sendFrame(sn);
    printf("\n************reciver********************\n");
    receiveACK(sn,3);
    resend(sn,3);

    return 0;
}