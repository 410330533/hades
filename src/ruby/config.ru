class App
  def call(env)
    puts env
    req = Rack::Request.new(env)

    case req.path_info
    when '/needle'
      status_code = 200
      body = IO.popen('top -b -n 1').readlines
    else
      status_code = 404
      body = ['']
    end

    headers = {
      'Content-Length' => body.join.length.to_s
    }
    [status_code, headers, body]
  end
end

run App.new
