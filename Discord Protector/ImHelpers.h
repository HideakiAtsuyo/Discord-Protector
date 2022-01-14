#pragma once

#include "imgui.h"
#include <vector>
#include <string>

using namespace std;

static const int kImGuiMargin = 10;

namespace ofxImGui
{

    bool VectorCombo(const char* label, int* currIndex, vector<string>& values, int height_items);
    bool VectorListBox(const char* label, int* currIndex, vector<string>& values, int height_items);
}
