// Copyright (c) 2020 Robert Vaser

#ifndef BIOSOUP_OVERLAP_HPP_
#define BIOSOUP_OVERLAP_HPP_

#include <cstdint>
#include <string>

namespace biosoup {

struct Overlap {
 public:
  Overlap() = default;

  Overlap(
      std::uint64_t lhs_id, std::uint32_t lhs_begin, std::uint32_t lhs_end,
      std::uint64_t rhs_id, std::uint32_t rhs_begin, std::uint32_t rhs_end,
      std::uint32_t score)
      : lhs_id(lhs_id),
        lhs_begin(lhs_begin),
        lhs_end(lhs_end),
        rhs_id(rhs_id),
        rhs_begin(rhs_begin),
        rhs_end(rhs_end),
        score(score),
        alignment() {}

  Overlap(
      std::uint64_t lhs_id, std::uint32_t lhs_begin, std::uint32_t lhs_end,
      std::uint64_t rhs_id, std::uint32_t rhs_begin, std::uint32_t rhs_end,
      std::uint32_t score,
      const std::string& alignment)
      : Overlap(
          lhs_id, lhs_begin, lhs_end,
          rhs_id, rhs_begin, rhs_end,
          score,
          alignment.c_str(), alignment.size()) {}

  Overlap(
      std::uint64_t lhs_id, std::uint32_t lhs_begin, std::uint32_t lhs_end,
      std::uint64_t rhs_id, std::uint32_t rhs_begin, std::uint32_t rhs_end,
      std::uint32_t score,
      const char* alignment, std::uint32_t alignment_length)
      : lhs_id(lhs_id),
        lhs_begin(lhs_begin),
        lhs_end(lhs_end),
        rhs_id(rhs_id),
        rhs_begin(rhs_begin),
        rhs_end(rhs_end),
        score(score),
        alignment(alignment, alignment_length) {}

  Overlap(const Overlap&) = default;
  Overlap& operator=(const Overlap&) = default;

  Overlap(Overlap&&) = default;
  Overlap& operator=(Overlap&&) = default;

  ~Overlap() = default;

  std::uint64_t lhs_id;  // (optional) LSB used for Watson-Crick strand
  std::uint32_t lhs_begin;
  std::uint32_t lhs_end;
  std::uint64_t rhs_id;
  std::uint32_t rhs_begin;
  std::uint32_t rhs_end;
  std::uint32_t score;  // heuristic or exact alignment score
  std::string alignment;  // (optional) cigar string
};

}  // namespace biosoup

#endif  // BIOSOUP_OVERLAP_HPP_
