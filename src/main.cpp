#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

struct item
{
    int item_id {0};
    int type_id {0};
    std::string name;
    std::string iai_name;
    std::string ai_textfile;
    int id {186};
    long position[3] {0, 0, 0};
    int team {1};
    int wpdistance {0};
    int wp_adv_trigger {0};
    int fov {180};
    int obliqueness {15};
    int waccuracy1 {100};
    int waccuracy2 {100};
    int perception2 {100};
    int perfectionist2 {100};
    int crouchtimer {3};
    int shoottimer {5};
    int attention {30};
    int advancetimer {10};
    int max_attack_distance {100};
    int edistances[2] {10, 100};
    std::string extra_mlink;
    int extra_val1 {0};
    int extra_val2 {0};
    int extra_val3 {0};
    int extra_val4 {0};
    int extra_val5 {0};
    int extra_valmode {0};
    int extra_bheight {20};
    std::string gen_string;
};

std::vector<item> items_vec;

int getSpaceCount(std::string& line)
{
    int space_count{0};
    for(char c : line)
        if(isspace(c))
            ++space_count;
    return space_count;
}

///position to correct
long ptoc(long &value)
{
    ///convert position long, to correct values
}

void findKey(std::vector<std::string>& top_keys_vec, std::vector<std::string>& keys_vec, std::ifstream& file)
{
    for(std::string line; getline(file, line);)
    {
        for(auto& key : keys_vec)
        {
            std::size_t found = line.find(key);
            if(found != std::string::npos)
            {
                unsigned int lend = key.length() + getSpaceCount(key)-1;
                std::cout << key << ": " << line.substr(lend) << std::endl;

                if(key == "  position")
                {
                    item x;
                    unsigned int len = key.length()+1;

                    std::stringstream ss(line.substr(len));
                    std::string delim_value;

                    int it{0};
                    while(std::getline(ss, delim_value, ' '))
                    {
                        std::cout << it << "[in]key: " << delim_value << std::endl;

                        x.position[it] = std::stol(delim_value); //double check

                        ++it;
                    }
                    items_vec.push_back(x);
                }
            }
        }
    }
}

int main()
{
    std::ifstream inFile;
    inFile.open(R"(C:\Users\---\CLionProjects\misreader\cm.mis)");

    std::vector<std::string> tk;
    std::vector<std::string> k;

    tk.emplace_back("begin item");

    k.emplace_back("  description");
    k.emplace_back("  position");

    findKey(tk, k, inFile);
    inFile.close();

    std::cout << "\nitem at 0, pos 0: " << items_vec.at(0).position[0] << std::flush;

    return 0;
}
