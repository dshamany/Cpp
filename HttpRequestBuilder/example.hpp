// Generated by https://quicktype.io

#pragma once

#include <boost/optional.hpp>
#include <stdexcept>
#include <regex>
class Image
{
public:
    Image() = default;
    virtual ~Image() = default;

private:
    std::string src;
    std::string name;
    int64_t h_offset;
    int64_t v_offset;
    std::string alignment;

public:
    const std::string &get_src() const { return src; }
    std::string &get_mutable_src() { return src; }
    void set_src(const std::string &value) { this->src = value; }

    const std::string &get_name() const { return name; }
    std::string &get_mutable_name() { return name; }
    void set_name(const std::string &value) { this->name = value; }

    const int64_t &get_h_offset() const { return h_offset; }
    int64_t &get_mutable_h_offset() { return h_offset; }
    void set_h_offset(const int64_t &value) { this->h_offset = value; }

    const int64_t &get_v_offset() const { return v_offset; }
    int64_t &get_mutable_v_offset() { return v_offset; }
    void set_v_offset(const int64_t &value) { this->v_offset = value; }

    const std::string &get_alignment() const { return alignment; }
    std::string &get_mutable_alignment() { return alignment; }
    void set_alignment(const std::string &value) { this->alignment = value; }
};

class Text
{
public:
    Text() = default;
    virtual ~Text() = default;

private:
    std::string data;
    int64_t size;
    std::string style;
    std::string name;
    int64_t h_offset;
    int64_t v_offset;
    std::string alignment;
    std::string on_mouse_up;

public:
    const std::string &get_data() const { return data; }
    std::string &get_mutable_data() { return data; }
    void set_data(const std::string &value) { this->data = value; }

    const int64_t &get_size() const { return size; }
    int64_t &get_mutable_size() { return size; }
    void set_size(const int64_t &value) { this->size = value; }

    const std::string &get_style() const { return style; }
    std::string &get_mutable_style() { return style; }
    void set_style(const std::string &value) { this->style = value; }

    const std::string &get_name() const { return name; }
    std::string &get_mutable_name() { return name; }
    void set_name(const std::string &value) { this->name = value; }

    const int64_t &get_h_offset() const { return h_offset; }
    int64_t &get_mutable_h_offset() { return h_offset; }
    void set_h_offset(const int64_t &value) { this->h_offset = value; }

    const int64_t &get_v_offset() const { return v_offset; }
    int64_t &get_mutable_v_offset() { return v_offset; }
    void set_v_offset(const int64_t &value) { this->v_offset = value; }

    const std::string &get_alignment() const { return alignment; }
    std::string &get_mutable_alignment() { return alignment; }
    void set_alignment(const std::string &value) { this->alignment = value; }

    const std::string &get_on_mouse_up() const { return on_mouse_up; }
    std::string &get_mutable_on_mouse_up() { return on_mouse_up; }
    void set_on_mouse_up(const std::string &value) { this->on_mouse_up = value; }
};

class Window
{
public:
    Window() = default;
    virtual ~Window() = default;

private:
    std::string title;
    std::string name;
    int64_t width;
    int64_t height;

public:
    const std::string &get_title() const { return title; }
    std::string &get_mutable_title() { return title; }
    void set_title(const std::string &value) { this->title = value; }

    const std::string &get_name() const { return name; }
    std::string &get_mutable_name() { return name; }
    void set_name(const std::string &value) { this->name = value; }

    const int64_t &get_width() const { return width; }
    int64_t &get_mutable_width() { return width; }
    void set_width(const int64_t &value) { this->width = value; }

    const int64_t &get_height() const { return height; }
    int64_t &get_mutable_height() { return height; }
    void set_height(const int64_t &value) { this->height = value; }
};

class Widget
{
public:
    Widget() = default;
    virtual ~Widget() = default;

private:
    std::string debug;
    Window window;
    Image image;
    Text text;

public:
    const std::string &get_debug() const { return debug; }
    std::string &get_mutable_debug() { return debug; }
    void set_debug(const std::string &value) { this->debug = value; }

    const Window &get_window() const { return window; }
    Window &get_mutable_window() { return window; }
    void set_window(const Window &value) { this->window = value; }

    const Image &get_image() const { return image; }
    Image &get_mutable_image() { return image; }
    void set_image(const Image &value) { this->image = value; }

    const Text &get_text() const { return text; }
    Text &get_mutable_text() { return text; }
    void set_text(const Text &value) { this->text = value; }
};

class Example
{
public:
    Example() = default;
    virtual ~Example() = default;

private:
    Widget widget;

public:
    const Widget &get_widget() const { return widget; }
    Widget &get_mutable_widget() { return widget; }
    void set_widget(const Widget &value) { this->widget = value; }
};
