#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H

#include <iostream>

namespace sdds {
    class Label {
        char* m_frame;
        char* m_content;
        int m_length;

        void setToDefault();
        void deallocate();

    public:
        Label();
        Label(const char* frameArg);
        Label(const char* frameArg, const char* content);
        ~Label();

        std::istream& readLabel();
        std::ostream& printLabel() const;
        Label& text(const char* content);
    };
}

#endif // SDDS_LABEL_H
