#include <iostream>
#include <filesystem>
#include <thread>

using namespace std;

class MyClass
{
public:
    void get_files(vector<string>& paths, const string& current_path) {
        for (const auto file : filesystem::directory_iterator(current_path)) {
            if (filesystem::is_directory(file)) {
                get_files(paths, file.path().string());
                paths.push_back(file.path().string());
                //this_thread::sleep_for(chrono::milliseconds(1));
                //cout << "ID потока = " << this_thread::get_id() << "\tsearching file\t" << endl;
            }
            else {
                paths.push_back(file.path().string());
            }
        }
    }

};
int main() {
    vector<string>paths;
    MyClass m;
    m.get_files(paths, "D://");
    /*thread t([&]() {
            m.get_files(paths, "D://"); 
            
        });*/
    string str = "workspace.xml"; 
    for (int i = 0; i < paths.size(); i++) {
        size_t pos = paths[i].find(str);
        if (pos != string::npos) {
            cout << paths[i] << endl;
            cout << "ID потока = " << this_thread::get_id() << "\tpath file\t" << endl;
            this_thread::sleep_for(chrono::milliseconds(6000));
        }

    }
    //t.join();
    return 0;

}