#pragma once

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
// TODO: remove this, create dependency between khustup and deped and use  DrawUpdateRawData from deped
class DrawUpdateRawData {
public:
    static constexpr std::size_t header_length = 8;
    static constexpr std::size_t max_body_length =
        1920 * 1200 * (4 + sizeof(bool) + 2 * sizeof(uint16_t)) /*image max size*/ +
        27 /*date YYYY/MM/DD/HH/MM/SS/MS/+UTC*/;

    DrawUpdateRawData();
    DrawUpdateRawData(const DrawUpdateRawData& other);
    DrawUpdateRawData(DrawUpdateRawData&& other);

    const char* data() const;

    char* data();

    std::size_t length() const;

    const char* body() const;
    char* body();

    char* header();
    const char* header() const;

    std::size_t body_length() const;

    void body_length(std::size_t new_length);

    bool decode_header();

    void encode_header();
    ~DrawUpdateRawData() { delete[] data_; }

private:
    char* data_;  //[header_length + max_body_length];
    std::size_t body_length_;
};
