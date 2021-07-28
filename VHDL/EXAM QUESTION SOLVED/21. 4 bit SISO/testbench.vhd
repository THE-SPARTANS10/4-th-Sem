-- Code your testbench here
library IEEE;
use IEEE.std_logic_1164.all;

entity testbench is
-- empty
end testbench; 

architecture tb of testbench is

-- DUT component
component SISO is
port(
    SISOCLK,INPUT : in std_logic;
    OUTPUT : out std_logic);
end component;

signal SISOCLK,INPUT,OUTPUT: std_logic;

begin

  -- Connect DUT
  DUT: SISO port map(SISOCLK,INPUT,OUTPUT);

    CLK_process: process
    begin
      for i in 1 to 8 loop
        SISOCLK<='0'; wait for 1 ns;
        SISOCLK<='1'; wait for 1 ns;
    end loop;
    wait;
  end process;
  
  sim_process: process
  begin
  	INPUT<='1'; wait for 2 ns;
    INPUT<='0'; wait for 2 ns;
    INPUT<='1'; wait for 2 ns;
    INPUT<='0'; wait for 2 ns;
    
    wait;
  end process;
end tb;