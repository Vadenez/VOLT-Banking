
class Configs {

public:

    bool save, debug;

    double balance;

    std::string username, pincode;


    std::string n = "error on name", p = "error on pin", d;

    double b;




    //string bal = (std::to_string(balance));

    void accfile() {

        std::string accName = "cfg/acc/";

        accName += username;
        accName += ".cfg";
        if (save == 1) {

            std::ofstream outfile;

            outfile.open(accName);

            outfile << username << endl << pincode << endl << balance;

            outfile.close();
        }
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
    void settingfile() {


        if (save == 1) {

            std::ofstream outfile;

            outfile.open("cfg/settings.cfg");

            outfile << debug << endl << "// 1 = debug on" << endl << "// 0 = debug off";

            outfile.close();
        }
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

class UserPassChecker {
public:
    bool nameCheck;
    std::string username, pin;

    std::string check() {
        if (nameCheck == 1) {
            int count = 0;

            for (int i = 0; i < username.size(); ++i)
                if (username[i] == ' ')
                    ++count;
            if (count > 0) {
                return "No spaces allowed";
            }
            else if (username.length() > 12)
                return "Only up to 12 letters and/or numbers";

            else {
                return "nice";
            }
                

        }
        else {
            if (pin.length() > 6) 
                return "Only up to 6 digits";

            else {
                return "nice";
            }
        }
    }
};








void error()
{
    PlaySound(TEXT("cfg/sound/winError.wav"), NULL, SND_FILENAME);
}
