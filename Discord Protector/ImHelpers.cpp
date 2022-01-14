#include "ImHelpers.h"

static auto vector_getter = [](void* vec, int idx, const char** out_text)
{
    auto& vector = *static_cast<std::vector<std::string>*>(vec);
    if (idx < 0 || idx >= static_cast<int>(vector.size())) { return false; }
    *out_text = vector.at(idx).c_str();
    return true;
};

bool ofxImGui::VectorCombo(const char* label, int* currIndex, std::vector<std::string>& values, int height_items)
{
    if (values.empty()) { return false; }
    return ImGui::Combo(label, currIndex, vector_getter,
        static_cast<void*>(&values), values.size(), height_items);
}

bool ofxImGui::VectorListBox(const char* label, int* currIndex, std::vector<std::string>& values, int height_items)
{
    if (values.empty()) { return false; }
    return ImGui::ListBox(label, currIndex, vector_getter,
        static_cast<void*>(&values), values.size(), height_items);
}
