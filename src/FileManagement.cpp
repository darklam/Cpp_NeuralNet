#ifndef FILEMANAGEMENT_H
#define FILEMANAGEMENT_H
#include "FileManagement.h"

FileManager::FileManager(){
  // Just some default values
  this->inputs = 2;
  this->outputs = 1;
  this->filename = "data.txt";
  this->separator = ',';
}

FileManager::FileManager(std::string filename){
  this->filename = filename;
  this->inputs = 2;
  this->outputs = 1;
  this->separator = ',';
}

FileManager::FileManager(std::string filename, char separator){
  this->filename = filename;
  this->inputs = 2;
  this->outputs = 1;
  this->separator = separator;
}

void FileManager::openFile(std::string filename){
  this->filename = filename;
  this->openFile();
}

void FileManager::openFile(){
  std::fstream file(this->filename, std::fstream::in);
  if(this->separator == ' '){
    std::string lol;
    while(file.good()){
      file >> lol;
      this->rawValues.push_back(std::stod(lol));
    }
  }else{
    std::string value;
    this->rawValues.clear();
    while(file.good()){
      std::getline(file, value, this->separator);
      this->rawValues.push_back(std::stod(value));
    }
  }
}

std::vector<double> FileManager::getRawValues(){
  return this->rawValues;
}

std::vector<std::vector<double>> FileManager::getInputs(){
  std::vector<std::vector<double>> out;
  std::vector<double> current;
  int i = 0;
  while(i < this->rawValues.size()){
    for(int j = 0; j < this->inputs; j++){
      current.push_back(this->rawValues[i++]);
    }
    out.push_back(current);
    current.clear();
    i += this->outputs;
  }
  return out;
}

std::vector<std::vector<double>> FileManager::getOutputs(){
  std::vector<std::vector<double>> out;
  std::vector<double> current;
  int i = this->inputs;
  while(i < this->rawValues.size()){
    for(int j = 0; j < this->outputs; j++){
      current.push_back(this->rawValues[i++]);
    }
    out.push_back(current);
    current.clear();
    i += this->inputs;
  }
  return out;
}

void FileManager::setInputs(int inputs){
  this->inputs = inputs;
}

void FileManager::setOutputs(int outputs){
  this->outputs = outputs;
}

void FileManager::setSeparator(char separator){
  this->separator = separator;
}

#endif
