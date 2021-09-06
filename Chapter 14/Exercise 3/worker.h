#ifndef WORKER_H
#define WORKER_H

#include <string>


class Worker
{
    public :
        Worker() : fullname("no one"), id(0L) {}
	      Worker(const std::string& s, long n) : fullname(s), id(n) {}
				virtual ~Worker() = 0;

				virtual void set() = 0;
				virtual void show() const = 0;


    protected :
        virtual void data() const;
        virtual void get();

    private :
        std::string fullname;
        long id;
};

class Waiter : virtual public Worker
{
  	public :
       	Waiter() : Worker(), panache(0) {}
	      Waiter(const std::string& s, long n, int p = 0) : Worker(s, n),
								                                          panache(p) {}
	      Waiter(const Worker& wk, int p = 0) : Worker(wk), panache(p) {}

				void set();
				void show() const;

  	protected :
				void data() const;
				void get();

  	private :
				int panache;
};

class Singer : virtual public Worker
{
  	public :
       	Singer() : Worker(), voice(other) {}
      	Singer(const std::string& s, long n, int v = other) : Worker(s, n),
			                                              					voice(v) {}
      	Singer(const Worker& wk, int v = other) : Worker(wk), voice(v) {}

				void set();
				void show() const;

  	protected :
				enum { other, alto, contralto, soprano, bass, baritone, tenor };
				enum { Vtypes = 7 };

				void data() const;
				void get();

  	private :
				static const char* pv[Vtypes];
				int voice;
};

class SingingWaiter : public Singer, public Waiter
{
  	public :
				SingingWaiter() {}
				SingingWaiter(const std::string& s, long n, int p = 0, int v = other)
				    : Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}
				SingingWaiter(const Worker& wk, int p = 0, int v = other)
						: Worker(wk), Waiter(wk, p), Singer(wk, v) {}
				SingingWaiter(const Waiter& wt, int v = other)
						: Worker(wt), Waiter(wt), Singer(wt, v) {}
				SingingWaiter(const Singer& wt, int p = 0)
					 	: Worker(wt), Waiter(wt, p), Singer(wt) {}

				void set();
				void show() const;

  	protected :
				void data() const;
				void get();
};

#endif
