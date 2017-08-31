#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class FileManager{
public:
  // Initialize the file manager with a filename
  FileManager(std::string);
  // Just create a FileManager object
  FileManager();
  // Initialize the file manager with a filename and
  // the value separator
  FileManager(std::string, char);
  // Opens the specified file for reading
  void openFile(std::string);
  // Opens the file selected for reading
  void openFile();
  // Sets the value separator
  void setSeparator(char);
  // Sets the number of inputs in the data set
  void setInputs(int);
  // Sets the number of outputs in the data set
  void setOutputs(int);
  // Returns a vector with the default values read
  std::vector<double> getRawValues();
  // Returns a vector with the input values read
  std::vector<std::vector<double>> getInputs();
  // Returns a vector with the outputs values read
  std::vector<std::vector<double>> getOutputs();

private:
  char separator;
  int inputs, outputs;
  std::vector<double> rawValues;
  std::string filename;
};
