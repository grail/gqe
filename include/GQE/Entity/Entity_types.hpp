/**
 * Provides the GQE Entity typedef's and forward class declarations.
 *
 * @file include/GQE/Entity/Entity_types.hpp
 * @author Jacob Dix
 * @date 20120423 - Initial Release
 * @date 20120616 - Fixed typedef comments
 * @date 20120618 - Changed name from typeInstanceID to typeEntityID
 * @date 20120623 - Add forward declaration of ISystem derived classes
 * @date 20120627 - Add forward declaration of ActionSystem classes
 * @date 20120720 - Moved PropertyManager to Core library
 */
#ifndef ENTITY_TYPES_HPP_INCLUDED
#define ENTITY_TYPES_HPP_INCLUDED

#include <string>
#include <queue>
#include <GQE/Config.hpp>
#include <GQE/Core.hpp>

namespace GQE
{
  // Forward declare GQE Entity interfaces provided
  class IAction;
  class IEntity;
  class ISystem;
  class ICollisionSystem;
  // Forward declare GQE Entity classes provided
  class Prototype;
  class Instance;
  class EntityEvents;
  class KeyBinder;
  class MouseBinder;
  class JoystickBinder;
  // Forward declare GQE Entity systems provided
  class ActionSystem;
  class AnimationSystem;
	class TransformSystem;
  class RenderSystem;

  /// Declare Action ID typedef which is used for identifying IAction objects
  typedef std::string typeActionID;

  /// Declare Entity ID typedef which is used for identifying IEntity objects
  typedef Uint32 typeEntityID;

  /// Declare Prototype ID typedef which is used for identifying Prototype objects
  typedef std::string typePrototypeID;

  /// Declare System ID typedef which is used for identifying ISystem objects
  typedef std::string typeSystemID;

	typedef std::map<std::string, Prototype*> typePrototypeList;
	typedef std::vector<sf::IntRect> typeRectList;
	//Types of input
	enum InputTypes
	{
	  INPUT_REALTIME,
	  INPUT_PRESSED,
	  INPUT_RELEASED,
    INPUT_MOTION
	};
  enum InputDevices
  {
    DEV_KEYBOARD,
    DEV_MOUSE,
    DEV_JOYSTICK,
    DEV_OTHER
  };
  enum Axis
  {
    AXIS_NONE=0,
    AXIS_HORZ=0x01,
    AXIS_VERT = 0x02,
    AXIS_POS = 0x04,
    AXIS_NEG = 0x08
  };
	/// Declare structs for handling data.
	//InputData Struct stores input data.
	struct InputData
	{
	  typeEventID EventID;
	  Uint32 Type;
    Uint32 Action;
    Uint32 Axis;
    Uint32 Device;
	};

  struct CollisionData
  {
    IEntity* MovingEntity;
    IEntity* OtherEntity;
    sf::Vector2f MinimumTranslation;
  };
  struct TimerData
  {
    sf::Clock Clock;
    sf::Time Time;
    std::string Event;
    bool Repeat;
    bool Active;
    GQE::Uint32 Action;
    TimerData() :
      Time(sf::Time::Zero),
      Event(""),
      Repeat(false),
      Active(false),
      Action(0)
    {

    }
    TimerData(sf::Time theTime, std::string theEvent, bool theRepeat, bool theActive, GQE::Uint32 theAction):
      Time(theTime),
      Event(theEvent),
      Repeat(theRepeat),
      Active(theActive),
      Action(theAction)
    {

    }
  };
  typedef std::map<std::string, TimerData> typeTimerLists;
  typedef std::map<Uint32, InputData > typeInputDataList;
}
#endif // ENTITY_TYPES_HPP_INCLUDED

/**
 * @ingroup Entity
 * A forward declaration of all classes, components, and interfaces provided by
 * the GQE Entity module/library.
 *
 * Copyright (c) 2010-2012 Jacob Dix
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

