-module(translate_service).
-export([loop/0, translate/2]).

loop() ->
    receive
        {From, "casa"} ->
            From ! "house",
            loop();
        {From, "blanca"} ->
            From ! "white",
            loop();
        {From, _} ->
            From ! "I don't understand.",
            loop()
end.

translate(To, Word) ->
    To ! {self(), Word},
    receive
        Translate -> Translate
    end.

% c(translate_service).
% Translator = spawn(fun translate_service:loop/0).
% translate_service:translate(Translator, "blanca").
% translate_service:translate(Translator, "casa").
