
//creates a class for saving cfg files
class Configs {

public:

    bool save, debug;

    double balance;

    std::string username, pincode;


    std::string n = "error on name", p = "error on pin", d;

    double b;

    //string bal = (std::to_string(balance));

    //for saving and loading login passwords and usernames
    void accfile() {

        //makes the created file corospond with the username, for easier infolder edits
        std::string accName = "cfg/acc/";
        accName += username;
        accName += ".cfg";

        //saves username, pincode and balance on different lines
        if (save == 1) {

            std::ofstream outfile;

            outfile.open(accName);

            outfile << username << endl << pincode << endl << balance;

            outfile.close();

        }

        //loads username, pincode and balance
        else {

            std::ifstream infile;

            infile.open(accName);

            infile >> n >> p >> b;

            username = n;
            pincode = p;
            balance = b;

            infile.close();

        }

    }

    //saves or loads current debug mode into file
    void settingfile() {

        //saves debug mode
        if (save == 1) {

            std::ofstream outfile;

            outfile.open("cfg/settings.cfg");

            outfile << debug << endl << "// 1 = debug on" << endl << "// 0 = debug off";

            outfile.close();

        }

        //loads debug mode
        else {

            std::ifstream infile;

            infile.open("cfg/settings.cfg");

            infile >> d;

            if (d == "1") {

                debug = 1;
            }

            else if (d == "0") {

                debug = 0;
            }

            infile.close();

        }

    }

};

//class for validation of username and password
class UserPassChecker {
public:

    bool nameCheck;

    std::string username, pin;

    //checks for validation
    std::string check() {

        int count = 0;

        for (int i = 0; i < username.size(); ++i)
            if (username[i] == ' ')
                ++count;

        if (count > 0)
            return "No spaces allowed";
        
        else if (username.length() > 12)
            return "Only up to 12 letters and/or numbers";

        else if (username.length() < 6)
            return "You have to have atleast 6 letters and/or numbers";

        else if (pin.length() < 4)
            return "You have to have atleast 4 digits";

        else if (pin.length() > 6)
            return "Only up to 6 digits";

        else {
            return "Check";

        }

    }

};

//plays a windows error like sound
void error()
{
    PlaySound(TEXT("cfg/sound/winError.wav"), NULL, SND_FILENAME);
}
