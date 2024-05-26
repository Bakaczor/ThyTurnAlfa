#include "CsvWriter.hpp"

CsvWriter::CsvWriter(const std::string& filename) {
    m_filestream.open(filename, std::ofstream::app);
    if (!m_filestream.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
    }
}

CsvWriter::~CsvWriter() {
    if (m_filestream.is_open()) {
        m_filestream.close();
    }
}

void CsvWriter::writeRow(const std::vector<std::string>& row) {
    for (unsigned int i = 0; i < row.size(); i++) {
        m_filestream << row[i];
        if (i != row.size() - 1) {
            m_filestream << ";";
        }
    }
    m_filestream << std::endl;
}
