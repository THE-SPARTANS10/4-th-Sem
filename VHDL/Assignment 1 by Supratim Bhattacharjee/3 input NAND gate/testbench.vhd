library ieee;
use ieee.std_logic_1164.all;

entity testbench is
--empty
end testbench;

architecture tb of testbench is
component three_input_nand is
port(
  a : in std_logic;
  b : in std_logic;
  c : in std_logic;
  y : out std_logic);
end component;

signal inp1,inp2,inp3,output: std_logic;

begin
  DUT: three_input_nand port map(inp1,inp2,inp3,output);
  
  process
  begin
    inp1<='0';
    inp2<='0';
    inp3<='0';
    wait for 0.5 ns;
    
    inp1<='0';
    inp2<='0';
    inp3<='1';
    wait for 0.5 ns;
    
    inp1<='0';
    inp2<='1';
    inp3<='0';
    wait for 0.5 ns;
    
    inp1<='0';
    inp2<='1';
    inp3<='1';
    wait for 0.5 ns;
    
    inp1<='1';
    inp2<='0';
    inp3<='0';
    wait for 0.5 ns;
    
    inp1<='1';
    inp2<='0';
    inp3<='1';
    wait for 0.5 ns;
    
    inp1<='1';
    inp2<='1';
    inp3<='0';
    wait for 0.5 ns;
    
    inp1<='1';
    inp2<='1';
    inp3<='1';
    wait for 0.5 ns;
    
    --clear
    inp1<='0';
    inp2<='0';
    inp3<='0';
    wait for 0.5 ns;
    wait;
    
  end process;
end tb;