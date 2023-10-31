// Copyright Louis Dionne 2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <dyno.hpp>

#include <cassert>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace dyno::literals;


template <typename Object>
using document_t = std::vector<Object>;

template <typename Document>
using history_t = std::vector<Document>;

template <typename T>
void draw(T const& t, std::ostream& out)
{ out << t << std::endl; }

template <typename Document>
void commit(history_t<Document>& x) {
  assert(!x.empty());
  x.push_back(x.back());
}

template <typename Document>
void undo(history_t<Document>& x) {
  assert(!x.empty());
  x.pop_back();
}

template <typename Document>
Document& current(history_t<Document>& x) {
  assert(!x.empty());
  return x.back();
}

struct my_class_t { };
void draw(my_class_t /*self*/, std::ostream& out)
{ out << "my_class_t" << std::endl; }

template <typename Object>
void draw(document_t<Object> const& self, std::ostream& out) {
  out << "<document>" << std::endl;
  for (auto const& x : self)
    draw(x, out);
  out << "</document>" << std::endl;
}



struct Drawable : decltype(dyno::requires_(
  "draw"_s = dyno::function<void (dyno::T const&, std::ostream&)>
)) { };

class object_t {
public:
  template <typename T>
  object_t(T x)
    : poly_{std::move(x), dyno::make_concept_map(
      "draw"_s = [](T const& self, std::ostream& out) { draw(self, out); }
    )}
  { }

  friend void draw(object_t const& x, std::ostream& out) {
    x.poly_.virtual_("draw"_s)(x.poly_, out);
  }

private:
  using Storage = dyno::shared_remote_storage;
  using VTable = dyno::vtable<dyno::remote<dyno::everything>>;
  dyno::poly<Drawable, Storage, VTable> poly_;
};


int main() {
  history_t<document_t<object_t>> h{1};
  current(h).emplace_back(0);
  current(h).emplace_back(std::string{"Hello!"});

  draw(current(h), std::cout);
  std::cout << "-------------------" << std::endl;

  commit(h);

  current(h).emplace_back(current(h));
  current(h).emplace_back(my_class_t{});
  current(h)[1] = std::string{"World"};

  draw(current(h), std::cout);
  std::cout << "-------------------" << std::endl;

  undo(h);

  draw(current(h), std::cout);
}
