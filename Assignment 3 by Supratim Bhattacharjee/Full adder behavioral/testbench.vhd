library ieee;
use ieee.std_logic_1164.all;

entity testbench is
--empty
end testbench;

architecture tb of testbench is
component full_adder is
port(
  x : in std_logic;
  y : in std_logic;
  z : in std_logic;
  s : out std_logic;
  c : out std_logic);
end component;

signal inp1,inp2,inp3,sum,carry: std_logic;

begin
  DUT: full_adder port map(inp1,inp2,inp3,sum,carry);
  
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