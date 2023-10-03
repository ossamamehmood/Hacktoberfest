// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

import "@openzeppelin/contracts/token/ERC20/ERC20.sol";
import "@openzeppelin/contracts/access/Ownable.sol";

contract CustomToken is ERC20, Ownable {
    string tokenName="OCTOBER"; //Custome Token Name
    string tokenAbbrv="OCT"; //Custom Token Abbreviation
    constructor() ERC20(tokenName, tokenAbbrv) {}

    function mintTokens(address recipient, uint256 amount) public onlyOwner {
        _mint(recipient, amount);
    }

    function burnTokens(uint256 amount) public {
    require(amount > 0, "Amount must be greater than zero");
    uint256 senderBalance = balanceOf(msg.sender);
    require(senderBalance >= amount, "Insufficient balance");
    _burn(msg.sender, amount);
    }


    function transfer(address recipient, uint256 amount) public override returns (bool) {
    require(recipient != address(0),"Invalid recipient address");
    return super.transfer(recipient, amount);
    }

    function getTotalSupply() public view returns (uint256) {
        return totalSupply();
    }
}
