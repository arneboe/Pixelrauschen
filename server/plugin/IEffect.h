#pragma once
#include <server/Types.h>
#include <cstdint>
#include <QtPlugin>
namespace plokid
{

  class IEffect
  {
  public:
    /** All necessary resources should be allocated on construction. */
    IEffect() {}

    /**Applies this effect to the @p pixels.
     * I.e. modifies the pixel values according to this effect
     * @param timeSinceLastCall Time since the last call in microseconds.
     *                          Depends on the framerate and is ***not*** constant
     * @note Try not to allocate large memory chunks in apply()*/
    virtual void apply(const uint32_t timeSinceLastCall, ArrayXXb &pixels) = 0;
  };
}

Q_DECLARE_INTERFACE(plokid::IEffect, "de.rnae.plokid.IEffect.v1")
