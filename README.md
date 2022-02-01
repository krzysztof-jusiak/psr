#Paper Scissors Rock - Game

* Design
  - Model View Controller
    - State Machine (https://www.omg.org/spec/UML/2.5.1/About-UML)
      ```
      @startuml
        [*] -> idle
        idle -> select : play / set_rounds
        select : select [is_current] / make_selection, next_player
        select -> shoot : select [is_last] / update_model
        shoot -> game_over : shoot [has_winner] / show_winner, add_points, next_round
        shoot -> game_over : shoot / next_round
        game_over -> [*] : play [out_of_rounds or already_won] / show_points
        game_over -> select : play / show_points, reset_player, reset_model
      @enduml
      ```

      > https://www.planttext.com/api/plantuml/png/VL7BRWCX3Bpp5JvN6-NUGvN_M4MM5Tm6XSKh0zdaxmiBURIHSa6CFJCsmoucqfGdRypuiOVD5pZhsTIZWiYU3ma-OVPqXMt12LLoiD7SM_qokeY7hCeXxGjpeXDZQpa90mI-9Amkh3TfzJ-A_FFm55U3F5jAZ9DOzgRnYk279aOvirRHMXoF575n8R1MMIak7Gv0rk8iBgJO5rXtV-UsVUOzseLRu-avZ98JodTF0aI1l3BPAouIxakqmNzDNl9y40TGhl6sZ6weFT_iEDZoIRy0

* Modes (`main.cpp`)
  - human vs human       - psr::human<0>,    psr::human<1>
  - computer vs computer - psr::computer<0>, psr::computer<1>
  - human first          - psr::human<0>,    psr::computer<1>
  - computer first       - psr::computer<0>, psr::human<1>
  ```cpp
  using game_t = psr::game<
    psr::human<0>,
    psr::computer<1>
  >;
  ```

* Vendor
  - DI     - C++14 Dependency Injection   - https://github.com/boost-ext/di
  - SML    - C++14 State Machine Language - https://github.com/boost-ext/sml
  - UT     - C++20 Unit Testing Framework - https://github.com/boost-ext/ut
  - fakeit - C++11 Mocking Framework      - https://github.com/eranpeer/FakeIt
