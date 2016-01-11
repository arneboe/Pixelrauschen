#pragma once
#include "Types.h"
#include <cstdint>

namespace plokid
{

  class IEffect
  {

    /** All necessary resources should be allocated on construction. */
    IEffect() {}

    /**Applies this effect to the @p pixels.
     * I.e. modifies the pixel values according to this effect
     * @param timeSinceLastCall Time since the last call in microseconds.
     *                          Depends on the framerate and is ***not*** constant
     * @note Try not to allocate large memory chunks in apply()*/
    void apply(const uint32_t timeSinceLastCall, ArrayXXb &pixels);
  };
}
