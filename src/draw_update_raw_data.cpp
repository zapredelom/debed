#include "draw_update_raw_data.h"

DrawUpdateRawData::DrawUpdateRawData() : data_(new char[header_length + max_body_length]),body_length_(0) {}


DrawUpdateRawData::DrawUpdateRawData(DrawUpdateRawData&& other) : body_length_(other.body_length_) {
    data_ = other.data_;
    other.data_ = nullptr;
}
DrawUpdateRawData::DrawUpdateRawData(const DrawUpdateRawData& other) : body_length_(other.body_length_) {
    data_ = new char[header_length + body_length_];
    std::memcpy(data_, other.data_, header_length + body_length_);
}

const char* DrawUpdateRawData::data() const { return data_; }

char* DrawUpdateRawData::data() { return data_; }

std::size_t DrawUpdateRawData::length() const { return header_length + body_length_; }

const char* DrawUpdateRawData::body() const { return data_ + header_length; }

char* DrawUpdateRawData::body() { return data_ + header_length; }


std::size_t DrawUpdateRawData::body_length() const { return body_length_; }

void DrawUpdateRawData::body_length(std::size_t new_length) {
    body_length_ = new_length;
    if (body_length_ > max_body_length)
        body_length_ = max_body_length;
}

bool DrawUpdateRawData::decode_header() {
    char header[header_length + 1] = "";
    std::strncat(header, data_, header_length);
    body_length_ = std::atoi(header);
    if (body_length_ > max_body_length) {
        body_length_ = 0;
        return false;
    }
    return true;
}

void DrawUpdateRawData::encode_header() {
    char header[header_length + 1] = "";
    std::sprintf(header, "%4d", static_cast<int>(body_length_));
    std::memcpy(data_, header, header_length);
}
