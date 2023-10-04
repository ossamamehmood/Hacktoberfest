`include "sr_latch.v"
module testbench();
    //inputs
    reg t_S, t_R, t_enable;

    //outputs
    wire t_Q, t_Q_bar;

    sr_latch S1(t_Q, t_Q_bar, t_S, t_R, t_enable);
    parameter stop_time = 80;
    initial begin
                t_S = 1'b1; t_R = 1'b0; t_enable = 1'b1;
            #10 t_S = 1'b0; t_R = 1'b0; t_enable = 1'b1;
            #10 t_S = 1'b0; t_R = 1'b1; t_enable = 1'b1;
            #10 t_S = 1'b0; t_R = 1'b1;
            #10 t_S = 1'b0; t_R = 1'b0;
        // #10 $finish;
    end

    initial #stop_time $finish;
    initial begin
        $monitor("time:%2d, E = %b, S = %b R = %b Q = %b Q' = %b", $time, t_enable, t_S, t_R, t_Q, t_Q_bar);
    end
endmodule