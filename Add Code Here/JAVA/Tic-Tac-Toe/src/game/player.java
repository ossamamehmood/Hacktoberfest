/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package game;

import game.type.pieces;

/**
 *
 * @author advance
 * github profile : https://github.com/Saurabh1999
 */
public class player {
    
    private String name;
    private int total_wins;
    private pieces piece_type;
    
    public player(pieces piece_type) {
        total_wins = 0;
        this.piece_type = piece_type;
    }
    
    public String get_name(){
        return name;
    }
    public void set_name(String name){
        this.name = name;
    }
    public pieces get_piece_type(){
        return piece_type;
    }
    public void set_piece_type(pieces piece_type){
        this.piece_type = piece_type;
    }
    public void increment_total_wins(){
        total_wins++;
    }
    
    public void reset_total_wins(){
        total_wins = 0;
    }
    public int get_total_wins(){
        return total_wins;
    }
    
}
