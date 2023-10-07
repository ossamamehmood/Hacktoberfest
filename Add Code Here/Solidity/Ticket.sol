// SPDX-License-Identifier: MIT

// Blockchain Smart Contract in solidity for ticket booking dapp
pragma solidity ^0.8.20;

contract TicketBooking {
    uint8 constant totalSeats = 20;
    uint8 constant maxSeatsPerAddress = 4;
    // uint8 lastSeat = 20;

    address public owner;
    mapping(uint => address) public seatToOwner;
    mapping(address => uint[]) public ownerToSeats;

    constructor() {
        owner = msg.sender;
    }

    modifier onlyOwner() {
        require(msg.sender == owner, "Only the contract owner can perform this action.");
        _;
    }

    function bookSeats(uint[] memory seatNumbers) public {
        require (lastSeat(seatNumbers),'Owner must not take last seat');
        require(seatNumbers.length > 0 && seatNumbers.length <= maxSeatsPerAddress, "Invalid number of seats.");
        // uint a = 0;
        
        require(consecutiveSeat(seatNumbers),'No consecutive seat');
        require(seatNumbersAreAvailable(seatNumbers), "Seats are not available.");
        
        for (uint i = 0; i < seatNumbers.length; i++) {
            uint seatNumber = seatNumbers[i];
            seatToOwner[seatNumber] = msg.sender;
            ownerToSeats[msg.sender].push(seatNumber);
        }
    }
    
    function showAvailableSeats() public view returns (uint[] memory) {
        uint[] memory availableSeats = new uint[](totalSeats - totalBookedSeats());
        uint index = 0;
        
        for (uint8 i = 1; i <= totalSeats; i++) {
            if (seatToOwner[i] == address(0)) {
                availableSeats[index] = i;
                index++;
            }
        }
        
        return availableSeats;
    }
    
    function checkAvailability(uint seatNumber) public view returns (bool) {
        require(seatNumber >= 1 && seatNumber <= totalSeats, "Invalid seat number.");
        return seatToOwner[seatNumber] == address(0);
    }
    
    function myTickets() public view returns (uint[] memory) {
        return ownerToSeats[msg.sender];
    }
    
    function totalBookedSeats() internal view returns (uint) {
        return totalSeats - showAvailableSeats().length;
    }

    function seatNumbersAreAvailable(uint[] memory seatNumbers) internal view returns (bool) {
        for (uint i = 0; i < seatNumbers.length; i++) {
            uint seatNumber = seatNumbers[i];
            if (seatNumber < 1 || seatNumber > totalSeats || seatToOwner[seatNumber] != address(0)) {
                return false;
            }
        }
        return true;
    }
    function consecutiveSeat(uint[] memory seatNumbers) internal pure returns(bool){
        for (uint i =0; i<(seatNumbers.length-1);i++){
            if(seatNumbers[i] == seatNumbers[i+1]){
                return false;
            }
        }
        return true;
    }
    function lastSeat(uint[] memory seatNumbers) internal view returns(bool){
        for (uint i =0; i<seatNumbers.length;i++){
            if(seatNumbers[i]==20 && owner == msg.sender){
                return false;
            }
        }
        return true;
    }
}
