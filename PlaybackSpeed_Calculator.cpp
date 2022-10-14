/* Below code helps user to determine how much time will be required to watch a video at any given playback speed. */

//including header files
#include <iostream>
using namespace std;

int main() 
{
    //Declaring necessary variables
    int hours, minutes, hours_to_minutes, videoLength, minutes_to_hours, actualLength, remaining_minutes ;
    float playbackSpeed;

    //Taking hours as input
    cout<<"\nEnter the hours of the video: ";
    cin>>hours;

    //Taking minutes as input
    cout<<"and the minutes: ";
    cin>>minutes;

    //Taking Playback speed as input
    cout<<"\nEnter Playback Speed in which you want to watch the video: ";
    cin>>playbackSpeed;
    

    //Calculation of playback speed 👇

    //Converting hours to minutes
    hours_to_minutes = hours*60;          

    //Calculating original length of video
    videoLength = hours_to_minutes + minutes;   

    //Calculating actual length of video after applying playback speed
    actualLength = videoLength/playbackSpeed;   

    //Converting minutes to hours 
    minutes_to_hours = actualLength/60;
    remaining_minutes = actualLength%60;

    //Giving the resultant time as output
    cout<<"\nIt will take "<<minutes_to_hours<<" hours and "<<remaining_minutes<<" minutes at "<<playbackSpeed<<" playback speed to watch the video.\n\n";

    return 0;
}