#include <string>
#include <vector>

namespace election {

// The election result struct is already created for you:

struct ElectionResult {
    // Name of the candidate
    std::string name{};
    // Number of votes the candidate has
    int votes{};
};

// TODO: Task 1
// vote_count takes a reference to an `ElectionResult` as an argument and will
// return the number of votes in the `ElectionResult.
int vote_count(ElectionResult& result) {
    return result.votes;
}

// TODO: Task 2
// increment_vote_count takes a reference to an `ElectionResult` as an argument
// and a number of votes (int), and will increment the `ElectionResult` by that
// number of votes.
void increment_vote_count(ElectionResult& result, int num_votes) {
    result.votes += num_votes;
}

// TODO: Task 3
// determine_result receives the reference to a final_count and returns a
// reference to the `ElectionResult` of the new president. It also changes the
// name of the winner by prefixing it with "President". The final count is given
// in the form of a `reference` to `std::vector<ElectionResult>`, a vector with
// `ElectionResults` of all the participating candidates.
ElectionResult& determine_result(std::vector<ElectionResult> final_count) {
    int winning_idx = 0, winning_val = 0, votes_at_idx;

    // Find the winner (whoever has the most votes).
    for (int idx = 0; idx < final_count.size(); idx++) {
        votes_at_idx = vote_count(final_count.at(idx));
        if (votes_at_idx > winning_val) {
            winning_idx = idx;
            winning_val = votes_at_idx;
        }

    }

    // Append president to the winner and return.
    ElectionResult& winner = final_count.at(winning_idx);
    winner.name = "President " + winner.name;
    int j = 3;
    return winner;
}

}  // namespace election