#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Label.h"

namespace sdds {
    Label::Label() {
        setToDefault();
    }

    Label::Label(const char* frameArg) {
        setToDefault();
        if (frameArg != nullptr) {
            m_frame = new char[strlen(frameArg) + 1];
            strcpy(m_frame, frameArg);
        }
    }

    Label::Label(const char* frameArg, const char* content) {
        setToDefault();
        if (frameArg != nullptr) {
            m_frame = new char[strlen(frameArg) + 1];
            strcpy(m_frame, frameArg);
        }
        text(content);
    }

    Label::~Label() {
        deallocate();
    }

    void Label::setToDefault() {
        m_frame = nullptr;
        m_content = nullptr;
        m_length = 0;
    }

    void Label::deallocate() {
        delete[] m_frame;
        delete[] m_content;
    }

    std::istream& Label::readLabel() {
        char content[71];
        std::cout << "> ";
        std::cin.getline(content, 71);
        text(content);
        return std::cin;
    }

    std::ostream& Label::printLabel() const {
        if (m_frame != nullptr) {
            int frameLen = strlen(m_frame);
            int contentLen = strlen(m_content);
            int labelWidth = contentLen < 70 ? contentLen + 2 : 72;

            std::cout << m_frame[0];
            for (int i = 0; i < labelWidth - 2; i++) {
                std::cout << m_frame[1];
            }
            std::cout << m_frame[2] << std::endl;

            std::cout << "|" << m_content;
            for (int i = 0; i < 70 - contentLen; i++) {
                std::cout << " ";
            }
            std::cout << "|" << std::endl;

            std::cout << m_frame[6];
            for (int i = 0; i < labelWidth - 2; i++) {
                std::cout << m_frame[7];
            }
            std::cout << m_frame[5];
        }
        return std::cout;
    }

    Label& Label::text(const char* content) {
        deallocate();
        m_length = strlen(content);
        m_content = new char[m_length + 1];
        strcpy(m_content, content);
        return *this;
    }
}

