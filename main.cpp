//FINAL PROJECT
/*This program will input numbers of insects and plants in an enclosed ecosystem, then input the length of time in each time interval, then simulate the ecosystem over the time interval until the user quits the program */
//Sarah Mather and Yenvy Chau

#include <iostream>

using namespace std;

//Conditions to find the number of each plant
int condFern (int numSnail, int numFern, int numSoil, int timeInterval);
int condShrub (int numShrub, int numBeetle, int numSoil, int timeInterval);
int condMoss (int numMoss, int numBeetle, int numShrub, int timeInterval);

//Conditions to find the number of each insect
int condSnail (int numSnail, int numFern, int timeInterval, int numSnCond);
int condSpider (int numSpider, int numBeetle, int timeInterval, int numSpCond);
int condBeetle (int numBeetle, int numShrub, int timeInterval, int numBCond);
int condWorm (int numWorm, int numSoil, int count, int timeInterval, int numWCond);

//Conditions to find the amount of soil
int condSoil (int numSoil, int numWorm, int count, int timeInterval);

//Checks to see if conditions have been met enough times
int checkSnail (int timeInterval, int numSnail, int numFern, int weeks, int numSnCond);
int checkSpider (int timeInterval, int numSpider, int numBeetle, int weeks, int numSpCond);
int checkBeetle (int timeInterval, int numBeetle, int numShrub, int weeks, int numBCond);
int checkWorm (int timeInterval, int numWorm, int numSoil, int weeks, int numWCond);
int checkFern (int timeInterval, int numFern, int numSnail, int weeks, int numFCond);
int checkShrub (int timeInterval, int numShrub, int numBeetle, int weeks, int numShCond);

int main ()
{
    //Welcome message
    cout << "Welcome to the ecosystem simulation!" << endl << endl;
    cout << "The plants to choose from are ferns, shrubs, and moss." << endl;

    //adding each variable
    int numFern=0;
    int numShrub=0;
    int numMoss=0;
    int numPlant=0;

    int numSnail=0;
    int numSpider=0;
    int numBeetle=0;
    int numWorm=0;
    int numInsect=0;


    //inputting the number of plants and insects, and the amount of soil
    while (numPlant <= 0)
    {
        cout << "Enter the number of each plant. You must have at least one plant." << endl;
        cout << "Enter the number of ferns." << endl;
        cin >> numFern;
        cout << "Enter the number of shrubs." << endl;
        cin >> numShrub;
        cout << "Enter the amount of moss (cm^2)." << endl;
        cin >> numMoss;
        numPlant = numFern+numShrub+numMoss;
    }

    cout << endl << "The insects to choose from are snails, spiders, worms, and beetles." << endl;

    while (numInsect <= 0)
    {
        cout << "Enter the number of each insect. You must have at least one insect." << endl;
        cout << "Enter the number of snails." << endl;
        cin >> numSnail;
        cout << "Enter the number of spiders." << endl;
        cin >> numSpider;
        cout << "Enter the number of beetles." << endl;
        cin >>numBeetle;
        cout << "Enter the number of worms." << endl;
        cin >> numWorm;
        numInsect = numSnail+numSpider+numWorm+numBeetle;
    }

    int numSoil = 0;
    while (numSoil < 100)
    {
        cout << endl << "Enter the amount of soil in mL. You must have at least 100 mL of soil." << endl;
        cin >> numSoil;
    }

    //inputting the time interval
    int timeInterval = 0;
    while (timeInterval < 1)
    {
        cout << endl << "Enter the length of each time interval in weeks (at least one week)." << endl;
        cin >> timeInterval;
    }

    int numSnCond;
    int numWCond;
    int numFCond;
    int numSpCond;
    int numBCond;
    int numShCond;


    int count = 1; //the number of time intervals that have passed
    int runProgram = 1; //as long as this number isn’t 0, the program will run
    int weeks=timeInterval*count;

    while (runProgram != 0)
    {
        if (weeks == 1)
        {
            cout << "After 1 week:" << endl << endl;
        }

        else
        {
            cout << "After "<<weeks<<" weeks:" << endl << endl;
        }
        // we made a change. Yay!
        cout << "Plants:" << endl;
        cout << "Ferns: " << condFern (numSnail, numFern, numSoil, timeInterval) << endl;
        cout<< "Shrubs: " << condShrub (numShrub, numBeetle, numSoil, timeInterval) << endl;
        cout << "Moss: " << condMoss (numMoss, numBeetle, numShrub, timeInterval) << endl << endl;
        cout << "Insects: " << endl;
        cout << "Snails: " << condSnail(numSnail, numFern, timeInterval, numSnCond) << endl;
        cout << "Spiders: " << condSpider (numSpider, numBeetle, timeInterval, numSpCond) << endl;
        cout << "Beetles: " << condBeetle (numBeetle, numShrub, timeInterval, numBCond) << endl;
        cout << "Worm: " << condWorm (numWorm, numSoil, count, timeInterval, numWCond) << endl << endl;
        cout << "Soil: " << condSoil (numSoil, numWorm, count, timeInterval) << endl;

        cout << "To end the simulation, enter 0. To continue, enter any other value." << endl;
        cin>>runProgram;
    }

    return 0;
}

//FUNCTIONS

//PLANT FUNCTIONS
//FERN and snail **ADD new function to check if conditions have been met, add int into variables
int condFern (int numSnail, int numFern, int numSoil, int timeInterval)
{
    int fernCount=0; //if the time interval is 1, checking when 2 weeks to kill fern
    for (int i=0; i<=numSnail; i++)
    {
        if ((numFern >=1 && timeInterval>=2) || (numFern >=1 && fernCount==2))
        {
            numFern=0;
            fernCount=0;
        }
        else if (numFern>=1 && timeInterval==1)
        {
            fernCount++;
        }
        else
        {
            numFern=0;
            if (timeInterval<=3)
            {
//numSnail--;
            }
        }
    }
    if (numSoil<100)
    {
        numFern=0;
    }
    return numFern;
}


//SHRUB and beetle GOOD **add function to check conditions
int condShrub (int numShrub, int numBeetle, int numSoil, int timeInterval)
{
    for (int i= 0; i < numBeetle; i++)
    {
        if (numShrub<=1 && numBeetle>0) //gets eaten by the beetle
        {
            numShrub-=1;
        }
        else
        {
            numShrub=0;
            if (timeInterval<=4)
            {
                numBeetle--;
            }
        }
    }
    numShrub++; //reproduces 1/week
    if (numSoil <150)
    {
        numShrub==0; //dies without enough soil
    }
    return numShrub;
}

//MOSS and beetle GOOD
int condMoss (int numMoss, int numBeetle, int numShrub, int timeInterval)
{
    if (numShrub==0 && numBeetle>0)
    {
        for (int i=0; i<=numBeetle; i++)
        {
            numMoss-=25; //gets eaten by beetles in absence of shrub
        }
    }
    if (numMoss>1)
    {
        numMoss+=12; //reproduces every week (12cm^2)
    }
    return numMoss;
}

//SNAIL and fern GOOD
int condSnail (int numSnail, int numFern, int timeInterval, int numSnCond)
{
    for (int i=0; i<=numSnail; i++) //for each snail
    {
        if (numSnCond==2) //if there have conditions have been met for 2 weeks
        {
            numSnail--;
            numSnCond=0;
        }
        else
        {
            //numFern=0;
            if (timeInterval<=3)
            {
                numSnail--;
            }
        }
    }
    return numSnail;
}


//SPIDER and beetle GOOD
int condSpider (int numSpider, int numBeetle, int timeInterval)
{
    for (int i= 0; i < numSpider; i++)
    {
        if (numBeetle)
        {
            numBeetle-=1;
        }
        else
        {
            numBeetle=0;
            if (timeInterval<=4)
            {
                numSpider--;
            }
        }

    }
    return numSpider;
}

//WORM and soil
int condWorm (int numWorm, int numSoil, int count, int timeInterval)
{
    if (numSoil<500) //dies after 2 weeks with less than 500 mL of soil
    {
        if (timeInterval==1 && count%2==0)
        {
            numWorm==0;
        }
        else if (timeInterval<=2)
        {
            numWorm==0;
        }
        else
        {
        }
    }
    int temp=0;
    for (int i=1; i<=timeInterval; i++)
    {
        for (int i=0; i<=numWorm; i++) //each worm produces 3 worms a week, produces 10mL of soil
        {
            temp+=3;
            numSoil=+10;
        }
        numWorm+=temp; //finding new number of worms
    }
    return numWorm;
}

//BEETLE and shrub GOOD
int condBeetle (int numBeetle, int numShrub, int timeInterval)
{
    for (int i= 0; i < numBeetle; i++)
    {
        if (numShrub<=1)
        {
            numShrub-=1;
        }
        else
        {
            numShrub=0;
            if (timeInterval<=4)
            {
                numBeetle--;
            }
        }
        return numBeetle;
    }
}

//SOIL and worm GOOD
int condSoil (int numSoil, int numWorm, int count, int timeInterval)
{
    int temp=0;
    for (int i=1; i<=timeInterval; i++)
    {
        for (int i=0; i<=numWorm; i++) //each worm produces 3 worms a week, produces 10mL of soil
        {
            temp+=3;
            numSoil+=10;
        }
        numWorm+=temp; //finding new number of worms
    }
    return numSoil;
}

//CHECKING TIME CONDITIONS
int checkSnail (int timeInterval, int numSnail, int numFern, int weeks, int numSnCond)
{
    int temp = numFern;
    if (temp<1) //if there are no ferns
    {
        numSnCond++; //the conditions are met once; snail will die if this happens twice
    }
//if numSnCond is two or greater, the conditions are met twice
    return numSnCond;
}
int checkSpider (int timeInterval, int numSpider, int numBeetle, int weeks, int numSpCond)
{

    return numSpCond;
}
int checkBeetle (int timeInterval, int numBeetle, int numShrub, int weeks, int numBCond)
{
    return numBCond;
}
int checkWorm (int timeInterval, int numWorm, int numSoil, int weeks, int numWCond)
{
    return numWCond;
}
int checkFern (int timeInterval, int numFern, int numSnail, int weeks, int numFCond)
{
    return numFCond;
}
int checkShrub (int timeInterval, int numShrub, int numBeetle, int weeks, int numShCond)
{
    return numShCond;
}
