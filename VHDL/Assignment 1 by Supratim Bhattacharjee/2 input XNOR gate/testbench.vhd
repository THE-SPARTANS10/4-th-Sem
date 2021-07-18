library ieee;
use ieee.std_logic_1164.all;

entity testbench is
--empty
end testbench;

architecture tb of testbench is
component two_input_xnor is
port(
  a : in std_logic;
  b : in std_logic;
  y : out std_logic);
end component;

signal inp1,inp2,output: std_logic;

begin
  DUT: two_input_xnor port map(inp1,inp2,output);
  
  process
  begin
    inp1<='0';
    inp2<='0';
    wait for 0.5 ns;
    
    inp1<='0';
    inp2<='1';
    wait for 0.5 ns;
    
    inp1<='1';
    inp2<='0';
    wait for 0.5 ns;
    
    inp1<='1';
    inp2<='1';
    wait for 0.5 ns;
    
    --clear
    inp1<='0';
    inp2<='0';
    wait for 0.5 ns;
    wait;
    
  end process;
end tb;