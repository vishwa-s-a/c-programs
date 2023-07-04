#include <iostream> 
#include <vector> 
#include <cstdlib> 
#include <ctime> 
using namespace std;
const int WINDOW_SIZE = 4;
const int TIMEOUT_DURATION = 3;
// Function to simulate frame corruption with a given probability 
bool isFrameCorrupted(double errorProbability) { 
 double randomValue = (double)rand() / RAND_MAX;
 return randomValue < errorProbability;
} 
// Function to simulate sending a frame 
void sendFrame(int frameNumber, double errorProbability) { 
 bool corrupted = isFrameCorrupted(errorProbability);
 if (!corrupted) { 
 cout << "Sent frame: " << frameNumber << endl;
 } else { 
 cout << "Frame " << frameNumber << " corrupted" << endl;
 } 
} 
// Function to simulate receiving an ACK or NAK 
bool receiveAckOrNak(int expectedSeqNum) { 
 int receivedSeqNum;
 cout << "Enter received SeqNum (ACK: positive, NAK: negative): ";
 cin >> receivedSeqNum;
 return receivedSeqNum == expectedSeqNum;
} 
// Function to simulate data transmission using Selective Repeat ARQ 
void transmitData(double errorProbability) { 
 int base = 0;
 int nextseqnum = 0;
 srand(time(0)); // Seed the random number generator
 while (base < 10) { 
 // Send frames within the window 
 for (int i = base; i < min(base + WINDOW_SIZE, 10); i++) {
sendFrame(i, errorProbability);
 nextseqnum++;
 } 
 // Start the timer 
 cout << "Timer started for frame: " << base << endl;
 bool timerExpired = false;
 // Wait for ACKs or NAKs 
 while (!timerExpired && base < 10) { 
 if (receiveAckOrNak(base)) { 
 cout << "ACK received for frame: " << base << endl;
 base++;
 cout << "Base updated to: " << base << endl;
 } else { 
 cout << "NAK received for frame: " << base << endl;
 sendFrame(base, errorProbability);
 } 
 } 
 // Resend frames from base onwards 
 if (timerExpired) { 
 cout << "Timer expired. Resending frames from: " << base << endl;
 nextseqnum = base;
 } else { 
 cout << "All frames acknowledged. Moving window forward." << endl;
 } 
 } 
} 
int main() { 
 double errorProbability;
 cout << "Enter frame corruption probability (0-1): ";
 cin >> errorProbability;
 transmitData(errorProbability);
 return 0;
}