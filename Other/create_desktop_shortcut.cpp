#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

const std::string VERSION = "0.0.2";

void setValue(const std::string &msg, std::string &value, bool required = false)
{
    std::string tmp = "";
    std::cout << msg << ": ";
    std::getline(std::cin, tmp);

    // handle required fields
    if (tmp == "" && required)
    {
        std::cerr << "This field is required\n";
        setValue(msg, value, required);
    }

    if (tmp != "")
    {
        value = tmp;
    }
}

int main(int argc, const char *argv[])
{
    std::cout << "Create Desktop Shortcut\nVersion: " << VERSION << "\n\n";
    std::string header = "[Desktop Entry]";
    std::string name = "Application_Name";
    std::string encoding = "UTF-8";
    std::string version = "1.0";
    std::string type = "Application";
    std::string terminal = "false";
    std::string exec_path = "/";
    std::string icon_path = "/";
    std::string categories = "";
    std::string keywords = "";
    std::string comment = "";

    setValue("REQUIRED Name", name, true);
    setValue("Encoding (default: UTF-8)", encoding);
    setValue("Version (default: 1.0)", version);
    setValue("Type (default: Application)", type);
    setValue("Terminal (default: false)", terminal);
    setValue("REQUIRED Path to Executable (e.g. /path/to/executable)", exec_path, true);
    setValue("REQUIRED Path to icon (e.g. /path/to/icon)", icon_path, true);
    setValue("Categories (e.g. Browser;Web)", categories);
    setValue("Keywords", keywords);
    setValue("Comment", comment);

    std::stringstream ss;

    ss << header << '\n'
       << "Name=" << name << '\n'
       << "Encoding=" << encoding << '\n'
       << "Version=" << version << '\n'
       << "Type=" << type << '\n'
       << "Terminal=" << terminal << '\n'
       << "Exec=" << exec_path << '\n'
       << "Icon=" << icon_path << '\n'
       << "Categories=" << categories << '\n'
       << "Keywords=" << keywords << '\n'
       << "Comment=" << comment << std::endl;

    std::string filename = name + ".desktop";
    std::ofstream file;
    file.open(filename);
    file << ss.str();

    std::string tmp = "mv " + filename + " $HOME/.local/share/applications/";
    system(tmp.c_str());
}
