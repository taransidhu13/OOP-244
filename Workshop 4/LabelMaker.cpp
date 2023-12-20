#include <iostream>
#include "LabelMaker.h"

namespace sdds {
    LabelMaker::LabelMaker(int noOfLabels) {
        m_noOfLabels = noOfLabels;
        m_labels = new Label[m_noOfLabels];
    }

    LabelMaker::~LabelMaker() {
        delete[] m_labels;
    }

    void LabelMaker::readLabels() {
        for (int i = 0; i < m_noOfLabels; i++) {
            std::cout << "Enter label number " << i + 1 << std::endl;
            m_labels[i].readLabel();
        }
    }

    void LabelMaker::printLabels() {
        for (int i = 0; i < m_noOfLabels; i++) {
            m_labels[i].printLabel();
            std::cout << std::endl;
        }
    }
}
