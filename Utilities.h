#pragma once
#include <iosfwd>
#include "Pixel.h"
#include "Image.h"

std::ostream& operator<<(std::ostream& os, const Pixel& p);
std::ostream& operator<<(std::ostream& os, const Image& A);