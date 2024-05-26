#pragma once

#ifndef CSV_WRITER_H
#define CSV_WRITER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class CsvWriter {
    public:
    CsvWriter(const std::string& filename);
    ~CsvWriter();

    void writeRow(const std::vector<std::string>& row);

    private:
    std::ofstream m_filestream;
};

#endif
