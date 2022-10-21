// SPDX-License-Identifier: UNLICENSED

pragma solidity ^0.8.7;

contract Vote{
    mapping(address=>bool) public voters; 
    address public Admin;   //0x5B38Da6a701c568545dCfcB03FcB875f56beddC4
    uint public noOfVoters;
    uint public deadline;
    // address public voters;

    struct Candidate{
        string name;
        uint noOfVotes;
        mapping(address=>bool) voters;
    }
    mapping(uint=>Candidate) public CandidatesList;
    uint public numOfCandidates;


    constructor(uint _noOfVoters, uint _deadline){
        noOfVoters = _noOfVoters;
        deadline = block.timestamp + _deadline;
        Admin = msg.sender;
    }    
    modifier onlyAdmin(){
        require(msg.sender==Admin, "not the Admin");
        _;
    }

    function addCandidate(string memory _name) public onlyAdmin{
        Candidate storage newCan = CandidatesList[numOfCandidates];
        numOfCandidates++;
        newCan.noOfVotes = 0;
        newCan.name = _name;
    }
    function voteCandidate(uint _CandidateNo) public {
        require(msg.sender!=Admin,"Admin! fuck off");
        require(block.timestamp < deadline, "Voting has ended");

        Candidate storage newVote = CandidatesList[_CandidateNo];

        require(newVote.voters[msg.sender] == false, "you have already voted");
        newVote.noOfVotes++;
        newVote.voters[msg.sender] = true;
    }

    function winnyyer() public view returns (uint winningProposal_){
        uint winningVoteCount = 0;
        for (uint p = 0; p < numOfCandidates; p++) {
            if (CandidatesList[p].noOfVotes > winningVoteCount) {
                winningVoteCount = CandidatesList[p].noOfVotes;
                winningProposal_ = p;
            }
        }
    }
}