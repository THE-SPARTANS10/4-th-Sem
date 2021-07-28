library IEEE;
use IEEE.std_logic_1164.all;

entity testbench is
--empty
end testbench;

architecture tb of testbench is

component siso_3_bit is
port(
  inp: in std_logic;
  clk: in std_logic;
  q3: out std_logic;
  q2: out std_logic;
  q1: out std_logic
);
end component;

signal inp_in,clk_in,q3_out,q2_out,q1_out: std_logic;
begin
  DUT: siso_3_bit port map(inp_in,clk_in,q3_out,q2_out,q1_out);
  process
    begin
      for i in 0 to 6 loop
        clk_in<='0';
        wait for 1 ns;
        clk_in<='1';
        wait for 1 ns;
      end loop;
    wait;
  end process;
  process
    begin
      inp_in<='1';
      wait for 2 ns;
      
      inp_in<='0';
      wait for 2 ns;
      
      inp_in<='1';
      wait for 2 ns;
      wait;
  end process;
end tb;