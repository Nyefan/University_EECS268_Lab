#pragma once
class BoardSpace
{
public: // Constructors
    /** A default constructor
    * @pre None
    * @post an empty boardSpace has been created;
    */
    BoardSpace(void);
    /** A constructor that maintains this objects location in a container for multiply linked applications;
    * @param i  The space number that this object corresponds to in an ordered container
    * @pre None
    * @post an empty boardSpace has been created that remembers it's initial location;
    */
    BoardSpace(int i);

private: // Internal functions and data objects
    int space;
    int numExits; // initialized to 0;
    bool beenUsed; // initialized to false;
    BoardSpace* exits[8];


public: // External functionality
    /** Adds a boardSpace that CAN come next in a sequence involving this boardSpace to this boardSpace's memory
    * @param *exitSpace
    * @pre this object has been constructed
    * @pre no more than 8 exitSpaces have already been added
    * @post exitSpace has been linked to this boardSpace, numExits++
    */
    void addExit(BoardSpace *exitSpace);
    /** Returns a pointer to the numExit'th exitSpace added
      * @param numExit  the number exit you wish to return
      * @pre at least numExit exitSpaces have been linked to this boardSpace using the function addExit
      * @post None
      * @return A pointer to the numExit'th exitSpace added
      */
    BoardSpace* getExit(int numExit);
    /** Returns the number of exits that have been added to this boardSpace
      * @pre None
      * @post None
      * @return The number of exits that have been added to this boardSpace
      */
    int getNumExits();
    /** Returns the number of exits linked to this boardSpace that are not toggled to "used"
      * @pre None
      * @post None
      * @return The number of exits linked to this boardSpace that are not toggled to "used"
      */
    int getNumUnusedExits();
    /** Returns the initial space in an ordered array that this object was constructed with;
      * @pre This object was constructed with the BoardSpace(int i) constructor;
      * @post None
      * @return the initial space in an ordered array that this object was constructed with
      */
    int getSpace();
    /** Returns the toggle state of "used"
      * @pre None
      * @post None
      * @return The toggle state of "used"
      */
    bool hasBeenUsed();
    /** Sets the toggle state of "used" to false
      * @pre None
      * @post The toggle state of "used" is false
      */
    void unuse();
    /** Sets the toggle state of "used" to true
      * @pre None
      * @post The toggle state of "used" is true
      */
    void use();
    
};

