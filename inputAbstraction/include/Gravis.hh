/**
 * PURPOSE:
 * ()
 *
 * LIBRARY DEPENDENCIES:
 * ((inputAbstraction/src/Gravis.cpp))
 */

#ifndef _GRAVIS_HH_
#define _GRAVIS_HH_

#include "SingleInput.hh"

namespace idf {

/**
 * represents a Gravis hand controller's input layout
 *
 * @author Derek Bankieris
 */
class Gravis {

    public:

    /** constructor */
    Gravis();

    /** up on the directional pad */
    SingleInput directionalPadUp;

    /** down on the directional pad */
    SingleInput directionalPadDown;

    /** left on the directional pad */
    SingleInput directionalPadLeft;

    /** right on the directional pad */
    SingleInput directionalPadRight;

    /** the button labeled select */
    SingleInput selectButton;

    /** the button labeled start */
    SingleInput startButton;

    /** the north (blue) button */
    SingleInput northButton;

    /** the east (green) button */
    SingleInput eastButton;

    /** the south (yellow) button */
    SingleInput southButton;

    /** the west (red) button */
    SingleInput westButton;

    /** the button labeled 1 above the side labeled L */
    SingleInput leftBumper1;

    /** the button labeled 2 above the side labeled L */
    SingleInput leftBumper2;

    /** the button labeled 1 above the side labeled R */
    SingleInput rightBumper1;

    /** the button labeled 2 above the side labeled R */
    SingleInput rightBumper2;

};

}

#endif
