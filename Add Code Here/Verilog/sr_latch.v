module sr_latch(output reg Q, output reg Q_bar, input S, R, enable);
    always @ (S or R) begin
        if(!enable) begin
            if (S==1 && R==0) begin
                Q <= 1;
                Q_bar <= 0;
            end

            if (S==0 && R==1) begin
                Q <= 0;
                Q_bar <= 1;
            end
        end
    end
endmodule