#pragma once

#ifndef CHOICE_H
#define CHOICE_H

#include <string>

struct Choice {
    std::string what;
    bool setWhat = false;
    unsigned int onWhom = 0;
    bool setOnWhom = false;
};

#endif
