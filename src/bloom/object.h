/**
 * \file Object.h
 * \author Xein <xgonip@gmail.com>
 * \date 11/20/2024
 *
 * \brief [Brief description of the file's purpose]
 */

#pragma once

namespace bloom {

class Object {

public:
  Object() = default;
  virtual ~Object() = default;

  // Functions
  virtual void Begin();
  virtual void Update();
  virtual void Destroy();

  // Variables

    
private:
    
    
};

}
