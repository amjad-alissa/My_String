#ifndef STRING_MYSTRING_H
#define STRING_MYSTRING_H

#include <iostream>
#include <cstdlib>

namespace Assignment06 {
    class MyString {
    private:

        /**
         * Attributes.
         * @var occupied Current number of characters
         * @var capacity Maximum number of characters
         * @var sequence Pointer to the beginning of the string array
         */
        size_t occupied;
        size_t capacity;
        char *sequence{};

        /**
         * Initialize occupied = 0, capacity = 1, sequence = new char[capacity]
         */
        void initialize_Empty();

    public:

        /**
         * Default Constructor.
         * Initialize occupied = 0, capacity = 1, sequence = new char[capacity]
         */
        MyString();

        /**
         * Constructor.
         * Initialize occupied = sizeOf(str), capacity = occupied + 1, sequence = str (deep copy)
         * @param str c-string
         */
        explicit MyString(const char str[]);

        /**
         * Constructor.
         * Initialize occupied = sizeOf(str), capacity = occupied + 1, sequence = str (deep copy)
         * @param str (cpp-string)
         */
        explicit MyString(const std::string str);

        /**
         * Copy Constructor.
         * Make a full copy of the passed object
         * @param source MyString Object to be copied
         */
        MyString(const MyString &source);

        /**
         * Destructor.
         * Free the dynamically allocated memory for the attribute sequence
         */
        virtual  ~MyString();

        /**
         * Overloading the operator+= with MyString object.
         * Setting the attributes: occupied += addend.occupied, capacity += addend.capacity, sequence += addend.sequence
         * @param addend Reference to MyString object to be concatenated with the calling object
         * @return Reference to the calling object after concatenation
         */
        MyString &operator+=(const MyString &addend);

        /**
         * Overloading the operator+= with c-string.
         * Setting the attributes: occupied += addend.occupied, capacity += addend.capacity, sequence += addend.sequence
         * @param addend c-string to be concatenated with the calling object
         * @return Reference to the calling object after concatenation
         */
        MyString &operator+=(const char addend[]);

        /**
         * Overloading the operator+= with single character.
         * Setting the attributes: occupied += addend.occupied, capacity += addend.capacity, sequence += addend.sequence
         * @param addend character to be concatenated with the calling object
         * @return Reference to the calling object after concatenation
         */
        MyString &operator+=(const char addend);

        /**
         * Overloading the operator= .
         * Setting the attributes: occupied = addend.occupied, capacity = addend.capacity, sequence = addend.sequence
         * @param source Reference to MyString object to be assigned to the calling object
         * @return Reference to the calling object after assignment
         */
        MyString &operator=(const MyString &source);

        /**
         * Overloading the operator[] .
         * @param position Index of the character to be returned
         * @return const Reference to the character at the specified index
         */
        const char &operator[](size_t position) const;

        /**
         * Overloading the operator[] .
         * Throws std::out_of_range exception if @param position > occupied or position < 0
         * @param position Index of the character to be accessed
         * @return Reference to the character at the specified index
         */
        char &operator[](size_t position);

        /**
         * Swapping two MyString objects.
         */
        void swap(MyString &);

        /**
         * Length of the string stored in @var sequence.
         * @return @var occupied
         */
        [[nodiscard]] std::size_t length() const {
            return occupied;
        }

        /**
         * C-string representation of the object.
         * @return const @var sequence
         */
        [[nodiscard]] const char *c_str() const {
            return sequence;
        }

        /**
         * Check if the object is empty.
         * @return TRUE if @var occupied == 0, Otherwise, FALSE.
         */
        bool is_empty() {
            return (occupied == 0);
        }

        /**
         * Friend Functions of the Class.
         * @function operator<<
         * @function operator>>
         * @function operator==
         * @function operator!=
         * @function operator>=
         * @function operator<=
         * @function operator>
         * @function operator<
         */
        friend std::ostream &operator<<(std::ostream &outs, const MyString &source);


        friend bool operator==(const MyString &s1, const MyString &s2);

        friend bool operator!=(const MyString &s1, const MyString &s2);

        friend bool operator>=(const MyString &s1, const MyString &s2);

        friend bool operator<=(const MyString &s1, const MyString &s2);

        friend bool operator>(const MyString &s1, const MyString &s2);

        friend bool operator<(const MyString &s1, const MyString &s2);
    };

    /**
     * Global Function, Overloading the operator+ for two MyString objects.
     * @param s1 MyString Object (First Operand)
     * @param s2 MyString Object (Second Operand)
     * @return MyString Object as a result of concatenating @param s1 with @param s2
     */
    MyString operator+(const MyString &s1, const MyString &s2);

    /**
     * Global Function, Overloading the operator+ for MyString object with C-string.
     * @param s1 MyString Object (First Operand)
     * @param s2 C-string (Second Operand)
     * @return MyString Object as a result of concatenating @param s1 with @param s2
     */
    MyString operator+(const MyString &s1, const char *s2);

    /**
     * Global Function, Overloading the operator+ for C-string with MyString object.
     * @param s1 C-string (First Operand)
     * @param s2 MyString Object (Second Operand)
     * @return MyString Object as a result of concatenating @param s1 with @param s2
     */
    MyString operator+(const char *s1, const MyString &s2);

    /**
     * Global Function, Overloading the operator== .
     * @param s1 MyString object (First Operand)
     * @param s2 MYString object (Second Operand)
     * @return True if (s1.occupied == s2.occupied && s1.capacity == s2.capacity && *s1.sequence == *s2.sequence),
     * False Otherwise
     */
    bool operator==(const MyString &s1, const MyString &s2);

    /**
     * Global Function, Overloading the operator!= .
     * @param s1 MyString object (First Operand)
     * @param s2 MYString object (Second Operand)
     * @return True if !(s1.occupied == s2.occupied && s1.capacity == s2.capacity && *s1.sequence == *s2.sequence),
     * False otherwise
     */
    bool operator!=(const MyString &s1, const MyString &s2);

    /**
     * Global Function, Overloading the operator>= .
     * @param s1 MyString object (First Operand)
     * @param s2 MYString object (Second Operand)
     * @return True if strcmp(s1,s2) >= 0, False Otherwise
     */
    bool operator>=(const MyString &s1, const MyString &s2);

    /**
     * Global Function, Overloading the operator<= .
     * @param s1 MyString object (First Operand)
     * @param s2 MYString object (Second Operand)
     * @return True if strcmp(s1,s2) <= 0, False Otherwise
     */
    bool operator<=(const MyString &s1, const MyString &s2);

    /**
     * Global Function, Overloading the operator> .
     * @param s1 MyString object (First Operand)
     * @param s2 MYString object (Second Operand)
     * @return True if strcmp(s1,s2) > 0, False Otherwise
     */
    bool operator>(const MyString &s1, const MyString &s2);

    /**
     * Global Function, Overloading the operator< .
     * @param s1 s1 MyString object (First Operand)
     * @param s2 s2 MYString object (Second Operand)
     * @return True if strcmp(s1,s2) < 0, False Otherwise
     */
    bool operator<(const MyString &s1, const MyString &s2);

    /**
     * Global Function, Overloading the operator<< .
     * Puts the characters stored at @var sequence into @param outs
     * @param outs Reference to output stream object
     * @param source Reference to MyString object
     * @return Reference to the passed output stream
     */
    std::ostream &operator<<(std::ostream &outs, const MyString &source);

    /**
     * Global Function, Overloading the operator>> .
     * Puts characters from @param ins into @var sequence (From the beginning of @param ins until the first white space character)
     * @param ins Reference to output stream object
     * @param target Reference to MyString object
     * @return Reference to the passed input stream
     */
    std::istream &operator>>(std::istream &ins, MyString &target);
}

#endif //STRING_MYSTRING_H
